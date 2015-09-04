
from iocbuilder import Xml
from iocbuilder import Substitution, AutoSubstitution, SetSimulation, Device, records, Architecture, IocDataStream
from iocbuilder.arginfo import *

from iocbuilder.modules.asyn import Asyn, AsynPort, AsynIP
from iocbuilder.modules.busy import Busy
from iocbuilder.modules.ADCore import ADCore, NDFileTemplate, ADBaseTemplate, simDetectorTemplate

class pilatusTemplate(AutoSubstitution):
    TemplateFile = "pilatus.template"
    SubstitutionOverwrites = [NDFileTemplate]

class pilatusXmlTemplate(Xml):
       TemplateFile = "pilatusTemplate.xml"

class pilatus(AsynPort):
    """Creates a pilatus areaDetector driver"""
    Dependencies = (ADCore,)
    _SpecificTemplate = pilatusTemplate
    def __init__(self, CAMSERVER = "localhost:41234", XSIZE = 1024, YSIZE = 768,
            BUFFERS = 50, MEMORY = 0, **args):
        # # Make an asyn IP port to talk to pilatus on
        # args["CAMSERVER_PORT"] = args["PORT"] + "ip"
        self.ip = AsynIP(CAMSERVER, name = args["PORT"] + "ip",
            input_eos = "\030", output_eos = "\n")
        # Init the superclass
        self.__super.__init__(**args)
        # Init the file writing class
        self.file = NDFileTemplate(**filter_dict(args, NDFileTemplate.ArgInfo.Names()))
        # Store the args
        self.__dict__.update(self.file.args)
        self.__dict__.update(locals())

    # __init__ arguments
    ArgInfo = ADBaseTemplate.ArgInfo + NDFileTemplate.ArgInfo + \
            _SpecificTemplate.ArgInfo.filtered(without = ["CAMSERVER_PORT"]) + \
            makeArgInfo(__init__,
        CAMSERVER = Simple('Machine:port that pilatus camserver is running on'),
        XSIZE = Simple('Maximum X dimension of the image', int),
        YSIZE = Simple('Maximum Y dimension of the image', int),
        BUFFERS = Simple('Maximum number of NDArray buffers to be created for '
            'plugin callbacks', int),
        MEMORY = Simple('Max memory to allocate, should be maxw*maxh*nbuffer '
            'for driver and all attached plugins', int))

    # Device attributes
    LibFileList = ['pilatusDetector']
    DbdFileList = ['pilatusDetectorSupport']

    def Initialise(self):
        print '# pilatusDetectorConfig(portName, serverPort, maxSizeX, ' \
            'maxSizeY, maxBuffers, maxMemory)'
        print 'pilatusDetectorConfig("%(PORT)s", "%(CAMSERVER_PORT)s", ' \
            '%(XSIZE)d, %(YSIZE)d, %(BUFFERS)d, %(MEMORY)d)' % self.__dict__

def pilatus_sim(**kwargs):
    return simDetector(2500, 2000, **kwargs)

SetSimulation(pilatus, pilatus_sim)

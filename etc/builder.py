
from iocbuilder import Xml
from iocbuilder import Substitution, AutoSubstitution, SetSimulation, Device, records, Architecture, IocDataStream
from iocbuilder.arginfo import *

from iocbuilder.modules.asyn import Asyn, AsynPort, AsynIP
from iocbuilder.modules.busy import Busy
from iocbuilder.modules.ADCore import ADCore, NDFileTemplate, ADBaseTemplate, simDetectorTemplate, makeTemplateInstance

class pilatusTemplate(AutoSubstitution):
    TemplateFile = "pilatus.template"
    #SubstitutionOverwrites = [NDFileTemplate]

class pilatusXmlTemplate(Xml):
       TemplateFile = "pilatusTemplate.xml"

class pilatusDetector(AsynPort):
    """Creates a pilatus areaDetector driver"""
    Dependencies = (ADCore,)
    _SpecificTemplate = pilatusTemplate
    def __init__(self, PORT = "pilatus1.CAM", CAMSERVER = "localhost:41234", XSIZE = 1024, YSIZE = 768,
                 BUFFERS = 50, MEMORY = 0, PRIORITY = 0, STACK_SIZE = 0, CBF_TRANSFER = 0,
                 CAMSERVER_HOST = "10.10.10.100", CBF_TEMPLATE_LOCATION = "/tmp/cbf_templates", **args):
        # # Make an asyn IP port to talk to pilatus on
        CAMSERVER_PORT = PORT + "ip"
        self.ip = AsynIP(CAMSERVER, name = PORT + "ip",
            input_eos = "\030", output_eos = "\n")
        # Init the superclass
        self.__super.__init__(PORT)
        # # Init the file writing class
        # self.file = NDFileTemplate(**filter_dict(args, NDFileTemplate.ArgInfo.Names()))
        # # Store the args
        # self.__dict__.update(self.file.args)
        self.__dict__.update(locals())
        makeTemplateInstance(self._SpecificTemplate, locals(), args)

    # __init__ arguments
    ArgInfo = ADBaseTemplate.ArgInfo + NDFileTemplate.ArgInfo + \
            _SpecificTemplate.ArgInfo.filtered(without = ["CAMSERVER_PORT"]) + \
            makeArgInfo(__init__,
        PORT = Simple('asyn port for pilatus detector'),
        CAMSERVER = Simple('Machine:port that pilatus camserver is running on'),
        XSIZE = Simple('Maximum X dimension of the image', int),
        YSIZE = Simple('Maximum Y dimension of the image', int),
        BUFFERS = Simple('Maximum number of NDArray buffers to be created for '
            'plugin callbacks', int),
        MEMORY = Simple('Max memory to allocate, should be maxw*maxh*nbuffer '
                        'for driver and all attached plugins', int),
        PRIORITY = Simple("Thread priority for the asyn port driver used for epicsThreadCreate call, 0 for epicsThreadPriorityMedium",int),
        STACK_SIZE = Simple("The stack size for the asyn port driver thread, 0 for epicsThreadGetStackSize(epicsThreadStackMedium)", int),
        CBF_TRANSFER = Simple("Disable/Enable cbf transfer to camserver host [0 to disable, otherwise enabled ]", int),
        CAMSERVER_HOST = Simple("Machine where camserver is running on, for cbf transfer"),
        CBF_TEMPLATE_LOCATION = Simple("Directory path in CAMSERVER_HOST where cbf templates are copied to"))

    # Device attributes
    LibFileList = ['pilatusDetector', 'cbfad']
    DbdFileList = ['pilatusDetectorSupport']

    def Initialise(self):
        print '# pilatusDetectorConfig(portName, serverPort, maxSizeX, ' \
            'maxSizeY, maxBuffers, maxMemory, priority, stack_size, cbf_transfer [0,1], camserver_host, cbfTemplateLocation)'
        print 'pilatusDetectorConfig("%(PORT)s", "%(CAMSERVER_PORT)s", ' \
            '%(XSIZE)d, %(YSIZE)d, %(BUFFERS)d, %(MEMORY)d, %(PRIORITY)d, %(STACK_SIZE)d, ' \
            '%(CBF_TRANSFER)d, %(CAMSERVER_HOST)s, %(CBF_TEMPLATE_LOCATION)s  )' % self.__dict__

def pilatus_sim(**kwargs):
    return simDetector(2500, 2000, **kwargs)

SetSimulation(pilatusDetector, pilatus_sim)

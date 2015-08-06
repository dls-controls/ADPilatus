CBF Template Transfer method
============================
Camserver supports the command
mxsettings cbf_template_file <path>
where path can be 0 or a file system location.

For the path to make sense the location has to be accessible to
camserver.  Dectris advises to set up the system where camserver runs
with no shared filesystem with the systems outside. The camserver
command only accepts the path, not the file itself as a "blob".  To
solve this, the cbf template needs to be passed by other means.

The implementation of the
mxsettings cbf_template_file <path>
can copy a file via "scp" to a location in the
detector computer where camserver runs.

The command executed is
scp source det@camserverHost:cbfTemplateLocation/basename(source)

The driver assumes that the user in camserverHost is "det".

To setup this, these are the steps needed:

1. the ioc needs to be run with an ssh-agent and an
identity that allows non-interactive ssh/scp.

2. set up the startup script for the pilatus driver with these three parameters

cbfTransfer (integer)
Set this to 0 to send the path directly to camserver. No copy is performed.
Set this to 1 to copy the template as part of mxsettings cbf_template_fil

camserverHost (string)
host to "scp" the source file to   

cbfTemplateLocation (string)
path in camserverHost where the source file is copied
The file is copied as
cbfTemplateLocation/basename(source)

The "source" string comes from the asyn parameter CBFTEMPLATEFILE

3. create in camserverHost the location and assign the appropriate permissions.

Example

The commands below generate a key without password, copy it to the
remote system (camserverHost - 10.10.10.100), load an agent and add
the key for non-interactive file transfers.

$ ssh-keygen -t rsa -N '' -f cbftransfer -C 'cbftransfer'
$ ssh-copy-id -i cbftransfer.pub det@10.10.10.100
$ eval `ssh-agent `
$ ssh-add cbftransfer


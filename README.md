# KuRemote
Remote control over OSC by apps uses ofxKuTextGui addon.

Project is made on openFrameworks.
It consists of two programs:
* KuRemote - main program, whic allows to control up to 16 programs,
* KuRemoteTst - test app, to which KuRemote could connect and remotely control.

## Binaries
[https://sourceforge.net/projects/kuremote/]

## Control keys for KuRemote:
* Esc - close app
* 1, 2, Shift+1, Shift+2 - choose the page (Settings, Comp01, ..., Comp16)
* Cursor - choose value to edit (name, address, port)
* [, ], Shift+[, Shift+] - edit value
* BackSpace - connect to the remove app, and disconnect back. After connection, KuRemote sends key presses to remote app,
and requests GUI description, and draws it on the screen. 

Remote app, such as KuRemoteTst, should contain object ofxKuTextGuiRemote class,
which will respond to KuRemote app requests.

## Build 
To build the projects KuRemote and KuRemoteTst:
1 install openFrameworks, 
2 install our ofxKuTextGui addon,
3 Create a new project with Project Generator (KuRemote / KuRemoteTst), which inclused ofxOsc and ofxKuTextGui addins
4 Press Generate.
5 Enjoy!



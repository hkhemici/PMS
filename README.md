#Pharmascience
#PatchFinder.exe

A simple program to learn whether the port of a Pharmascience switch can be used to patch a user.
An active port that was unused for 3 months is considered fit to attribute to a new user.

Latest release: v1.0.1

HOW TO USE:

To run this program, you need:
- The NAME of a SWITCH;
- Its NUMBER in the STACK;
- The NUMBER of a PORT that is currently free on the switch;

You can gather the information above from a trip to a patch room or from browsing the switch log files available at:
\\\MONITOR02-RM\Open_Switch_Ports$

PatchFinder (a.k.a Patch King 3000) will then parse the relevant log files to tell you whether you can use the port you specified.

Special thanks to Robin Wood Jammot for a lot of crucial information!

Outline of the algorithm:
- Read switch name/number/port
- Generate names of log files generated during the last 90 days (3 months) for the given switch.
- Parse the log files for the desired port.
- When the port is found, check if its status is "notconnected".
- If "notconnected", try for 3 months, return true (fit for use) if the port has been "notconnect" for 3 months (excluding days when no log files were generated), return false otherwise.
- if the port is anything other than "notconnected" (ex.: "disabled", "connected"), return false (not fit for use).

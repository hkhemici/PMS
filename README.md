##Pharmascience
#PatchFinder.exe

A simple program to learn whether the port of a Pharmascience switch can be used to patch a user (on any site!).
An active port that has not been used for 3 months is considered fit to attribute to a new user.

Latest release: v1.0.1

##HOW TO USE IT:

To run this program, you need:
- The **name** of a **switch** (case-sensitive!);
- Its **number** in the **stack**;
- The **number** of a **port** that is currently free on the switch;

You can gather the information above from a trip to a patch room, but I recommend double-checking the port/stack notation in the log files stored in:
**\\\MONITOR02-RM\Open_Switch_Ports$**

PatchFinder (a.k.a Patch King 3000) will then parse the relevant log files to tell you whether you can use the port you specified.

Special thanks to Robin Wood Jammot for a lot of crucial information!

Outline of the algorithm:
- Read switch name/number/port.
- Generate names of log files generated during the last 90 days (3 months) for the given switch.
- Parse the log files for the desired port.
- When the port is found, check if its status is "notconnected".
- If "notconnected", try for 3 months, return true (fit for use) if the port has been "notconnect" for 3 months (excluding days when no log files were generated), return false otherwise.
- if the port is anything other than "notconnected" (ex.: "disabled", "connected"), return false (not fit for use).

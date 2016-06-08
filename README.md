#Pharmascience
#PatchFinder.exe

A simple program to look up the port of a switch in the automatically generated log files at PMS.
An active port that was unused for 3 months is considered fit to attribute to a new user.

Outline of the algorithm:
- Read switch name
- Read switch port
- Generate names of log files generated during the last 90 days (3 months) for the given switch.
- Parse the log files for the desired port.
- When found port, tell if notconnected.
- if not notconnected, return false (not fit for use).
- if notconnected, try for 3 months, after, return true (fit for use).

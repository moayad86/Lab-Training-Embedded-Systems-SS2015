# Lab-Training-Embedded-Systems-SS2015
Moayad Alydaghshi &amp; Rafik Al-Hallak Project 

# Task Description
Diode and Transistor Detection:
An arduino-based circuit should be able to detect diodes and transistors as well as the anode and catode of an connected diode, or the base, collector and emitter of an transistor. Indication of the detection results should be done via LEDs. The constructed circuit has to have appropriate drop-in contacts for the elements and self-explaining (labeled) LEDs.

# Solution idea
# Diode
The current in diode only flow in one direction, so it can be detected easily by using it as a switch for the circuit, and the circuit will be closed and the current will flow only if the diode is set in the right direction. 
# Transistor
Distinguish between transistors types and legs is a harder problem. The idea is to use the transistor as a switch, so the circuit will be closed when the current flow between Emitter and Collector, and we have two cases for this. First is NPN transistor, and the circuit will be closed when there are High input on the Base and High on Collector or Emitter. Second is PNP transistor, and the circuit will be closed when there are Low input on the Base and High on Collector or Emitter. The detection depends on testing all possibilities for the three legs. 

 

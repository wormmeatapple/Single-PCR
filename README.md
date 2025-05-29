# Single-PCR
A cheap, easy to use single tube PCR thermocycler for biotech.
For Hack Club's Highway event!

<p>Polymerase-chain-reaction (PCR for short) is a vital reaction used in all sorts of biology fields. It amplifies a predetermined segment of dna, doubling it every cycle! PCR has three steps; 1. Get quite hot (95c) to split apart dna 2. Cool back down to allow little marker pieces of rna to anneal to the big, now detached dna 3. Heat back up to allow little protein machines to create more dna! This repeats 20-40 times until you have BILLIONS of copies of a specific piece of dna. This cycling is often done in very expensive, university level PCR thermocyclers that use peltier modules to heat and cool dynamically. My design does the same heating and cooling by using much cheaper components, resistive heaters and cpu fans. (Back in the day they used heated water baths!). I aim for Single-PCR to be a cheap easy PCR alternative for hobbyists. It'll be controlled by an ESP-8266 board broadcasting a control website. From the control website you can adjust cycles, monitor temperature data, abort reactions etc. Creating this vital piece of hardware would allow me to preform tons of different biohacking protocols, and if I can make it cheap enough, maybe it'll let others do the same!<p/>
  
![singlepcr](https://github.com/user-attachments/assets/57526e4f-2b63-4971-b00f-a8f1cf9f75b2)

|Item name|What the item is for in your project|Item source|Item price (include shipping + taxes)|Total price|
|--------|-------------------------------------|------------|-------------------------------------|------------|
|Aluminium heating block|To hold the PCR tube,and to be heated and cooled by the heating elements/cooling fans|JLCPCB CNC manufacturing|60.56+27.66 shipping|88.22|
|Heating element 2 pcs|To heat the heating block and thus the tube inside it.|https://www.aliexpress.com/item/1005007920697887.html?|2.92+9.36 shipping|12.28|
|10kΩ NTC Thermistor 10 pcs|To give temperature readings so the microcontroller knows when to heat/cool.|https://www.aliexpress.com/item/1005008177000786.html?|3.51+0 shipping|3.51|
|12V 1A wall-mounted DC power supply|Supply 12V power to the heaters and the fan.|https://www.aliexpress.com/item/1005005763465796.html?|5.08+0 shipping|5.08|
|Thermal paste|Increase thermal conductivity between heaters and heating block.|https://www.aliexpress.com/item/1005007037912738.html?|4.29+0 shipping|4.29|
|Transistors (12V)|Allow the microcontroller to control whether the fan gets power.|https://www.aliexpress.com/item/1005008370773690.html?|1.82+0 shipping|1.82|
|DC Fans 2 pcs|Blow air across the heatsink fins to cool down the heating block.|https://www.aliexpress.com/item/1005006306536871.html?|10.60+0 shipping|10.60|
|ESP control board|Read temperature data, control transistors, broadcast control website to user.|My cupboard|Free!I have some|0.00|
|**Total**||| |**125.80 AUS**/**80.60 USD**|


<br>
<br>

![image](https://github.com/user-attachments/assets/997a0c95-cd43-40da-928f-4e63ec8a9f26)

![image](https://github.com/user-attachments/assets/7b88c4be-4c2a-458c-b1ff-ba4a0fbab18f)


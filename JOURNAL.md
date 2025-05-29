---
title: "Single-PCR"
author: "wormmeatapple"
description: "A tiny PCR machine designed to be cheap and easy"
created_at: "24th/5/2025"
time taken: 9 hours
---







## May 24th

> Created repo  
> Found the parts I'm going to need; heater elements and thermistors  
> Started 3d modelling based on selected parts

![image](https://github.com/user-attachments/assets/de11b594-d925-4bd1-9255-a8776a0591ef)

<p>I want to try and limit how much material is between the heaters and the tube, so I'm using a quite thin wall. I did ask people in the #cad channel what they thought of this but at time of writing I didn't get a reply</p>

![image](https://github.com/user-attachments/assets/5650ea54-2c5b-4ad7-a798-8dba2974d1ba)

<p>Heatsink fans on one side, now just to mirror them.</p>

![image](https://github.com/user-attachments/assets/40fbdced-8c0c-4988-9b4c-23ba652d32f9)

<p>Very nice! We now have a hole for the PCR tube to go in, a hole for the thermistor, slots for the heaters and heatsinks to cool down easier. I'm not sure how well this'll be CNCed as I've never ordered a CNC part before but hopefully nothing breaks.</p>

> Time taken: about **30 mins**  
> - Modelling  
> - Researching parts

## Still May 24th

<p> Spent a ton of time researching and compiling parts. While not very technical, it's time that's very much needed. I also now know the specs of everything, so I can start writing code to control it all!</p>

> Time taken: **1 hour**
> - Compiling BOM
> - Researched all parts

## May 25th

>Started designing a wiring circuit

<p>First time ever using a pcb designer, but I'm slowly making process on the wiring schematic. I'm making it on easy-ada designer and since it technically isn't really a pcb alot of the parts I need aren't there.</p>
<p>This could maybe be a pcb? It'd be kinda small but it'd make wiring everything slightly easier? Something for me to think about.</p>
<p>Just as I was about to take a screenshot, website froze up and erased my progress. -__- I can't prove it either which sucks. Ah well, an hour wasted. Time for lunch.</p>

<br>

![image](https://github.com/user-attachments/assets/b33ebf33-7667-4e2e-b76a-817bc692a982)

<p>Screenshotting more frequently this time.</p>

![image](https://github.com/user-attachments/assets/d2600720-afca-4a2b-a599-02bedaee6edc)

<p>Fans and thermistor circuit all wired up, now just the heaters.</p>

![image](https://github.com/user-attachments/assets/43ed2df9-5c4e-4e4d-84af-f810dcfb3b5d)

<p>Done! I'm sure I could of done it better, faster and with the proper parts, but for the first time designing a circuit like this I think I did alright. I'll send it into the highway chat and see if anyone finds an issue in it.</p>
<p>As soon as I wrote that I looked back on it and wanted to make a couple of changes, one second...</p>

![image](https://github.com/user-attachments/assets/fd2d1dfa-7e6c-4d29-92c5-ef26e763ff6b)

<p>Much nicer. The old format made sense, but for someone who isn't as well versed in circuitry this is way easier to follow</p>

> Time taken **1h 57m**
> - Wired up all components
> - Lost an hour to a crash :sob:

<p>Got some feedback on my schematic. Mainly that I should wire the heaters in parellal and I should change the relay for a transistor.</p>

![image](https://github.com/user-attachments/assets/1c6f5f81-f6f4-4666-90af-4c815929eaa2)

> Time taken **7m**
> - Finally learnt how to tell if something is parellal 


> Now time to code up the control side of everything
<p>My plan is to have a website that the esp8266 broadcasts and the user connects to. Once you've connected you can choose the cycle times and monitor the temperature.</p>

![image](https://github.com/user-attachments/assets/ff01be47-3d08-4474-95cc-b3db13fd879e)

<p>Stupid port 6 only opens when I'm in device manager.</p>
<p>So weird, I keep getting a "permission denied" error for my com port?</p>
<p>Ohhhhh, having serial monitor open counts as a connection, so arduino ide wasn't free to flash. Everything is back to working now.</p>
<p>Just fiddled around with the code for a while before I realised it was trying to be a station not an access point. 🤦</p>

![image](https://github.com/user-attachments/assets/76f2c024-5c42-4aef-8e66-1e0a5b5f8e00)

<p>Was going to take this screenshot to complaing about how it isn't working, but instead found my phone is just refusing to display the html. In other news, finally have a prototype! Now I can start drafting the other functions I need like reading temp and making a cycle.</p>

<p>Code now handles different links. Not exactly necessary as everything needed by the user is on the homepage, but is useful for AJAX (acting like I didn't learn what AJAX was today</p>

<p>Now a div in the html is updated every second with the readings from the thermistor using AJAX. Preferably I would like it to be graphed over time and overlayed on the user's requested cycle, but the only graphing option I've found relies on using an external JS libary.</p>

![image](https://github.com/user-attachments/assets/4b2066a8-d48a-4bd9-ab47-3fe6b88a5b04)

<p>So messy. I can't even read it.</p>


<p>That's it for today. All and all pretty efficient. Posting the arduino sketch right after I commit this.</p>

> Time taken **2h 27m**
> - Added webserver functions to controller
> - Added simple temperature function
> - AJAX to continously update page with temperature data
> - Started adding fan/heater control

## May 26th

<p>Just got three things left to do before I submit,</p>

> - Add graphing while offline
> - Add a way to specify cycles that the controller reads and then actually does
> - Overlay the temp graph and the cycle graph (probably easiest?)

<p>Gonna work on the graphing first. In my research I kept seeing people suggest the Chartly.JS library, but this doesn't work while offline. Hm</p>

<p>I think I've found a solution. I'm gonna install LittleFS on my board and than just store the js libary on my esp? I hope</p>

<p>Why won't the tool show up in the tool dropdown?</p>

![image](https://github.com/user-attachments/assets/15c306af-9721-4779-bd6f-4abb44bb9b99)

<p>That's annoying. I've just spent ages (futilely) trying to get the uploader to show in the tool dropdown, but I just checked the size of chartly and it's more than the flash size. Awesome. I guess I'll have the board act as an AP and a STA so that it has wifi access. Booooo.</p>

<p>I'm deciding to temporarily put the graphing on hold and focus on the actual functionality of turning the heater and fan on and off to reach a desired temp.</p>

<p>Now that I'm making it, why is this thing website operated? It can't keep a substantial memory so it wouldn't be able to store preset cycles decided by the user or anything like that. I'll keep the webserver stuff for now, but when it's done it'll probably just be used to start the cycle and read the temp 👎</p>

<p>Actually no, the cycles will stay the same, but depending on the GC content of the dna being PCRed, denaturation has to change. So instead it'll be like a form where you input how long the denature and extension steps have to be. Honestly such a relief, I thought all my webserver shenanigans would be a waste.</p>

<p>Okay I've actually figured out a procedure that actually makes sense. When you boot up the machine you follow these steps. 1. Connect to the access point 2. Enter in your PCR settings like number of cycles, length of each phase, temp of each phase etc 3. Hit start 4. Watch the temp graph</p>

![image](https://github.com/user-attachments/assets/8609dbec-ca75-4a0f-b461-07f449c13abf)

<p>I've added in a function to control the heat simply by polling the therm, if lower than the ideal heat turn on heaters, if higher turn on fans. Than I put it into the loop connected to an if statement that turns on when you submit the form of variables. All the durations and ideal temps are governed by the variables that you chose from the form. !!! It should all be good and working! Just need to fix up the html. Also sidenote I don't know the proper way to do it but why can't I just have this function be void. If it has any arguements has to return something like bruh.</p>

<p>Blank white screen on my arduino ide. Worrying.</p>

<p>Was able to press save despite the blank screen of nothing. Maybe I should make a backup...</p>

![image](https://github.com/user-attachments/assets/53604f30-c064-444c-89c0-ec0816cb4fd2)

<p>Pretty simple cycle mechanic. I do wonder if the delays in the cycle() function will stop the handleclient() function from working. I guess we'll find out eventually</p>

<p>Tested out everything and it seems to work. Forms send info, info gets converted to variables, variables control cycle, cycle controls pins. I even got the pins to light up an led, so it should be all good to go! I do wonder if there's a cheaper way to get my heating block CNCed though. I'll ask highway.</p>

> Time taken
> - **3h 2m**
> - Rethought of project design
> - User data converted to cycle settings
> - cycle settings control pins

<p>Gonna submit it today, I'm scared that I'll be missing something really simple and have to wait a week before submitting again. I definitly could have made this quicker, but I always choose to do new things for these events, I suppose that's the point though.</p>

## May 29th

<p>Got some feedback from @alexren, so I thought I'd talk a little about how a typical PCR machine works in detail (I'll add a simplier version to the readme).</p>

<p>If you've read the readme of this project, you know a PCR machine's main goal is to just change the temperature of a little chemical reaction in a repeating nature. The thousand dollar ones found in universities and real labs use peltier modules, which is essentially an electric heat pump.</p>

![image](https://github.com/user-attachments/assets/4655d614-4ab1-453d-9481-7ef53ff2edc8)

<p>If you power it, one side gets cold and the other gets hot. Flip the polarities and the hot and cold sides switch. So, a good PCR machine has your standard heating block to allow smooth temp distribution, and then some high quality peltiers stuck to it, allowing you to switch between hot and cold preeeety quick. Now I'm not a university or million dollar biotech lab, so I've gotta use a different method. I have to do heating through a ceramic resistance based heater, and cooling through a fan and heatsink. This works fine, if slightly slower to reach the appropriate temps, because the temperature PCR occurs at is pretty warm anyway. All the fan is doing is reversing the heating process essentially. So my heater gets the heat block (and thus the PCR tube) hot, and then the fan cools it back down quicker than ambient heat loss would. There is technically one thing about a regular PCR machine that I can't emulate. Usually after a PCR reaction has finished cycling and done the final extension step, the peltiers cool it all the way down to around 4c. This is just to protect the dna since it's a pretty delicate molecule, and transforming a broken piece of dna into something is a bad idea. To combat this, if you use Single-PCR, just be there when the reaction finishes to move your dna into the freezer 👍.</p>




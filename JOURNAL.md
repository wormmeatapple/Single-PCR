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






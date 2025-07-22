# CREW XR Utilities 

CREW XR Utilities is an Unreal Engine Plugin developed by CREW, that contains basic assets for the development of a multiplayer VR experience, with XR components such as hand tracking, physics, 1st person point of view and so on.

It contains:
- Different components of our Manu Avatar, such as Skeletal Mesh, Mesh, Skeleton, animation sequences, animation blueprint, control rig, IK rig, Physics asset and T pose.
- an XR player for the immersants or performer, with hand tracking.
![Screenshot 2025-05-23 115256](https://github.com/user-attachments/assets/0a9e4d5d-29d7-4766-8bbd-7d974b503b0f)

***
Requirements:
- Unreal Engine 5.3
- [Download](https://github.com/CREW-Brussels/CREWXRUtilities.git) the plugin's folder in the Plugins folder of your project here or if your project is on git, add this command in the Plugins folder of your project:
```
git submodule add https://github.com/CREW-Brussels/CREWXRUtilities.git
```
***

## GOOD TO KNOW
Whenever you'd like to use one of of the components, never modify them directly from the PLUGIN: always create a blueprint inherited from those assets.

## Set up VR with our XR tools 

In order to use our XR settings to launch a new VR experience: 
- make sure it's in play in VR
- Create a new GameMode for your VR experience with our XR Player

![Screenshot 2025-05-23 115307](https://github.com/user-attachments/assets/6c4506e0-656e-4122-a8f4-28d0ee591810)

## Decide on the visibility of the first person POV
To decide on the visibility of the players, use the nodes "hidden in game" with the conditions you'd like to apply.

***

## About
<img src="https://github.com/user-attachments/assets/2ffa225b-2966-4f68-8106-3fd403fd6988" alt="CREW-LOGO" width="130"/>  
<img src="https://emil-xr.eu/wp-content/uploads/2022/10/logo_emil-272x300.png)" alt="EMIL-XR-LOGO" width="100"/>

> CREW XR Utilities, a submodule of EXP, is being developed by [CREW](http://crew.brussels) as part of [EMIL](https://emil-xr.eu/), the European Media and Immersion Lab, an Innovation Action funded by the European Union and co-funded by Innovate UK. 

## Funding
<img src="https://emil-xr.eu/wp-content/uploads/2022/10/EN-Funded-by-the-EU-POS-1024x215.png)" alt="EU" height="100"/>

> This project has received funding from the European Union's Horizon Europe Research and Innovation Programme under Grant Agreement No 101070533 EMIL.

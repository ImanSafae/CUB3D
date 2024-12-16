# CUB3D

This is CUB3D, a C project of the school 42 common core, and the second graphics project after FRACT-OL.
Just like the latter, CUB3D uses the MinilibX.
The goal is to create a game in "3D" using the method of raycasting, inspired by the game Wolfenstein 3D.
The method I chose uses trgonometry;
![image](https://github.com/user-attachments/assets/173ec318-4f81-472e-8a2f-d54a751aea97)

The goal is to be able to move through a maze, using the arrow keys. The walls should have textures and the floor and ceiling should be one color. Anything added is a bonus. The program takes a map as a parameter on the command line, a few already made maps are available in the repository.
The textures theme I chose is inspired from a famous game:
![image](https://github.com/user-attachments/assets/44c1b58e-46d3-40b5-abe6-1515897fa3f1)


Among the bonuses I chose to add:
- a minimap in the top right corner of the screen
- collisions against the wall: you cannot walk _through_ the walls
- doors that can be opened or closed (with the space bar)
- the point of view can change with the use of the mouse scroll

I also took the liberty to add a few non-required features (which wasn't listed in the subject requirements or bonuses):
- There are randomly generated frames on the walls: when the map is loaded and displayed, there is a 1/14 chance for each piece of wall that instead of the basic wall texture, it will be a frame (so about 7%). The frame texture is also randomly chosen as 1 of 7. These frames are the ones you can find in the castle from the original game this is inspired from.
- Among y
- A different game mode (playable with the map_tig.cub map), where there's only doors instead of walls, and you have 30 secondes to find the only real door or you're there stuck forever. A chronometer is displayed on the screen. This is achieved through multi-threading.

![image](https://github.com/user-attachments/assets/3980bd98-020d-4c98-8c6c-f18c822cd4cd)



<div align="center">
  <h1>
    So_long
  </h1>
  <blockquote>
    So long and thanks for all the fish
  </blockquote>
</div>

---

<h2 align="center">
  Objective
</h2>

The objective of this project is to build a 2D game using the school graphical library (MinilibX) where you have the player character that has to get all the collectibles and get to the exit.

The bonus part you also have to add an enemy, a sprite animation and a movement count displayed directly on the screen.

![image](https://user-images.githubusercontent.com/76601093/196158201-1ff31fe0-3a19-4c8a-8101-67d83a5dbb73.png)

---

<h2 align="center">
	How to install minilbx
</h2>

    git clone https://github.com/42Paris/minilibx-linux.git
    cd minilibx-linux

    sudo apt install libxext-dev libxrandr-dev libx11-dev libbsd-dev libssl-dev

    make
    
	cd /usr/local/man/
	sudo mkdir man1

    (Return to the minilibx-linux directory)

    sudo cp man/man1/* /usr/local/man/man1/
    sudo cp libmlx.a /usr/local/lib/
    sudo cp mlx.h /usr/local/include/
    
    man mlx
    (Must show the minilibx manual)

---

<h2 align="center">
  How to run:
</h2>

- ```make```
- ```./so_long maps/map.ber``` (you can change the map or make a new one)

IMPORTANT: This game was made for Mac, you can open the game but may not be able to move on linux because of the key bindings.

---

<img src="https://user-images.githubusercontent.com/76601093/196039712-ffd15bb3-8fd2-4aac-b8a1-f5a4481836e4.jpg" width=340 align="left">
<img src="https://user-images.githubusercontent.com/76601093/196062667-ea71cc7d-9a36-4ce6-a420-00c82b1872f6.png">

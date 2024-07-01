# so_long 

Core concept avec pseudo code : 
https://42-cursus.gitbook.io/guide/rank-02/so_long/core-concepts

Ressources en plus pour les tileset / pixel art et so_long tester : 
https://github.com/jotavare/42-resources?tab=readme-ov-file#so_long

Info sur so_long + minilibx : 

https://reactive.so/post/42-a-comprehensive-guide-to-so_long

https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html

https://pulgamecanica.herokuapp.com/posts/minilibx-tutorial

https://github.com/pulgamecanica/42Course/tree/main/42Documentation (mlx docummentation)

https://reactive.so/post/42-a-comprehensive-guide-to-so_long (guide so_long)

https://www.piskelapp.com/ (create pixel art)

https://itch.io/game-assets/free/tag-sprites (assets)

https://www.freecodecamp.org/news/flood-fill-algorithm-explained/ (parsing the map)

https://en.wikipedia.org/wiki/Flood_fill (algo for parsing the map)



Road map : 
            
            - Map
      
  - [x] Parse the map
    - [x] When parsing the map you can already check some errors, before even going further
    - [x] Does the map file exist ?
    - [x] Is the map rectangular ?
      - [x] All the lines should be the same length.
    - [x] Is there something in the map file ?
    - [x] Is the map enclosed in walls ?
      - [x] Check the first and last lines and columns, they should all be 1 (WALL)
    - [x] Is there only one exit ?
      - [x] Simply count how many E you find on the map.
    - [x] Is there only one start position ?
      - [x] Simply count how many P you find on the map.
    - [x] Is there at least one collectibles ?
      - [x]  Simply count how many C you find on the map.
      - [x] Check if there is a valid path to exit and collect (flood fill)

             - Game checklist :

   - [x] Create a window using MiniLibX
      - [x] Create the required structure to store all the necessary information

   - [x] Load all the required sprites (images) for your game and store them into memory

   - [x] Create the different hooks
      - [x] key_handler
      - [x] mouse_handler (if necessary)
      - [x] close_handler, this is a hook on the red cross that closes the program correctly
      - [x] loop_hook (=> you game loop)
        
               - Render checklist :
   - [x] Draw the background
   - [x] Draw the not movable parts of the map (border)
   - [x] Draw the player

               - Key handler :
         
The key handler, is mainly used to call the update_player_position function when W, A, S or D is pressed or to close the program correctly when we press the ESC key.
   - [x] Is the requested new position a Wall ?
        - [x] if the new position is a Wall, don't do anything. The subject says that the player should not be able to go through walls
   - [x] Is the requested new position inside the map ?
       - [x] if the new position is outside the map, don't do anything. Normally this shouldn't happen since the map is enclosed in walls but hey, never too sure.
       - [x] the requested new position a Collectible ?
          - [x] if yes, update the collected items counter and check
             - [x] check if all collectibles have been collected
                - [x] if yes, unlock the exit
      - [x] update your map 2D array and replace the collectible by a "floor" tile so that it is not drawn in the next iteration of the game loop.
      - [x] If the requested new position is not a wall, nor a collectible, nor outside the map, simply set the player position to the requested new position.
   



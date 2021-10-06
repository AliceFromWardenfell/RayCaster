# RayCaster

\**This project is not finished yet, therefore available only on Linux (also check mlx_linux/[README.md](https://github.com/AliceFromWardenfell/ray_caster/tree/prototype/mlx_linux#readme) for dependencies)*  

Task definition: [subject](https://drive.google.com/file/d/1GSw6MvFF1_2BSFv96Tjlru2bgLr-ZIil/view?usp=sharing)

This project is written according to the [Norm](https://drive.google.com/file/d/1cf_thz7IUjWxVRlPbDyfv0hACNSz9_9s/view?usp=sharing).

### Instructions:
1. Type "make" in the root directory  
2. Execute ./cub3D test_level.cub  

#### Controls:
MOVE: W | A | S | D  
ROTATE: left arrow | right arrow
#### \*.cub settings:
* R - resolution
* NO - path to the texture of the north side of the cubes
* EA - path to the texture of the east side of the cubes
* SO - path to the texture of the south side of the cubes
* WE - path to the texture of the west side of the cubes
* S - path to the sprite
* F - floor color \[0-255, 0-255, 0-255\]
* C - ceiling color \[0-255, 0-255, 0-255\]
#### Map settings:
* 0 - nothing (walkable square)
* 1 - a wall
* 2 - a sprite
* S - starting position of the player looking south (N, W, E for other directions)
#### Valid map example:
```
1111111111  
1000000001  
1001111001  
1001  1001111  
1001  1000021  
1001111001111  
1000000S01  
1111111111
```

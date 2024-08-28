# miniRT

miniRT created by [@nikkxll](https://github.com/nikkxll) and [@dnapi](https://github.com/dnapi)

This project is about creating own Raytracer using the MLX42 power

## Configuration file

Example of configuration file for ```colors.rt``` scene
```
# Camera's position and direction
R 1000 800
# Ambient Light
# <intensity: 0-1> <color: red, green, blue>
A                      0.1        255,255,255

# Camera
# <coordinates of camera position: x,y,z> <camera view: x,y,z> <pov:x,y,z>
C   0,10,0         0,-1,1   60

# Light
# <coordinates: x,y,z> <brightness: 0-1> <color:red,green,blue>
l   0,10,15               0.3           255,0,255
l   0,10,10                0.3         	255,0,0
l   0,10,5               0.3           0,255,255
l   -5,10,10              0.3           0,0,255
l   5,10,10               0.3           255,255,0

# Sphere
# <coordinates: x,y,z> <diameter> <color:red,green,blue>
sp  0,2,10              4           255,255,255

# Plane 
# <coordinates: x,y,z> <origin:x,y,z> <color:red,green,blue>
pl  0,-2,0            0,1,0              255,255,255
pl  0,10,0            0,1,0              255,255,255
```

## Results

✅ Passed with 125/100 ✅

**Some of the scenes:**

<img width="996" alt="Screenshot 2024-08-28 at 9 39 29" src="https://github.com/user-attachments/assets/b46efc7a-4912-4822-b8ca-7b8687f81488">

*colors.rt*

<img width="795" alt="Screenshot 2024-08-28 at 9 40 33" src="https://github.com/user-attachments/assets/279916bc-77a7-47bc-a6d3-1e318b763e06">

*room.rt*

<img width="1018" alt="Screenshot 2024-08-28 at 9 41 41" src="https://github.com/user-attachments/assets/08ebd82c-d732-4829-af63-8e2cdda87b1d">

*cornellbox.rt*

<img width="796" alt="Screenshot 2024-08-28 at 9 44 37" src="https://github.com/user-attachments/assets/30ad7d38-400a-4d72-9911-999ae630298b">

*atom_with_checker.rt*

___
dnikifor: dnikifor@student.hive.fi | apimikov: apimikov@student.hive.fi

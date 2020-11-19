Your task is to implement an Image Gallery using React.
All of your code should be written in the index.jsx file;
( do not modify any of the existing HTML / CSS code! )

You need to implement the following behavior:

Autoplay:
The big image should cycle through the list of images each 3 seconds,
except when it's paused.
Next button
When the button is pressed, the current image is changed to the next one
If the current image was the last one, the first image should be selected after pressing the button
Previous button
When the button is pressed, the current image is changed to the previous one.
If the current image was the first one, the last image should be selected after pressing the button.
Play/Pause button
When the button is pressed, the button icon should be changed to the opposite (the play icon should be changed into the pause icon, and vice versa).
Thumbnail images list
Clicking a thumbnail should change the big image.
The currently selected thumbnail should be highlighted.
Feel free to modify the given code as you wish.

Note: It is not allowed to add your own imports, but "react" module is already imported. So, if you'd like to use some methods from this module, instead of importing them feel free to use them directly:

import { methodA, methodB } from "react";

methodA(...);
methodB(...);
can be safely changed to

React.methodA(...);
React.methodB(...);
Bonus: Add extra features ✨.
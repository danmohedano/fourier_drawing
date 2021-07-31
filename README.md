# Fourier Drawing
Inspired by [3blue1brown's](https://www.youtube.com/watch?v=r6sGWTCMz2k) video on the topic, the program attempts to use the [Fourier Transform](https://en.wikipedia.org/wiki/Fourier_transform) to describe a drawing as a series of rotating vectors.

## Requirements
- SDL Library. To install in Linux/Unix, simply use `sudo apt-get install libsdl2-2.0 libsdl2-dev`

## Usage
After executing the program, the user can input through a series of mouse movements a drawing for a period of 5 seconds (this duration can be configured in the `config.h` header. Once the process is finished, the program calculates the configuration of vectors and represents their movement, representing in yellow the resulting new generated points and in pink the original points recorded during the input phase. 

## Description
For a detailed description of the mathematics and inner workings of the idea, refer to [3blue1brown's](https://www.youtube.com/watch?v=r6sGWTCMz2k) video.
As an overview, the program calculates the vectors using the following formula:

![vector_formula](https://user-images.githubusercontent.com/43313293/127736648-2352867f-f1c1-4279-a666-807fdcedb760.jpg)

The constant complex number `Cn` responsible for the adjustment of the initial angle and length of each vector is calculated applying the Fourier Transform (with `f(t)` being the function for which it is calculating the transform, in this case, the points of the drawing).

![constant_formula](https://user-images.githubusercontent.com/43313293/127736827-8ace6840-7b49-4921-8126-de522d53202a.jpg)

## Future Updates
- Improve user input functionality
- Implement image input (possible use of SVG)
- Improve data representation or Migrate to different library/framework

# Pathtracer

A small pathtracer implemented in C++. It's by far not finished, but it can render some simple scenes in a reasonable time.
For any more complex scenes it is not performant enough however. OpenMP can be used to improve performance (approx. by a factor of 4)

## Usage
1. Download stb_image_write.h from https://github.com/nothings/stb
2. Create a folder "output" in you working directory
3. compile the files (e.g. ```g++ -std=c++11 -Wall -g *.cpp */*.cpp -I/path/to/stb_image_write```)
4. run the compiled program (e.g ```./a.out```)

If OpenMP is installed you can compile/run it with OpenMP to get a small performance increase.

## Results
<img src="https://i.imgur.com/z2isMr0.jpg">
<p align="center">
<img src="https://i.imgur.com/Nr8wIyf.png" width="33%">
<img src="https://i.imgur.com/2mbhaMK.png" width="33%">
<img src="https://i.imgur.com/ia1csnj.png" width="33%">
</p>

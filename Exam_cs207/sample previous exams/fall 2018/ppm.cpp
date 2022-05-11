#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct pixel{
    int R; int G; int B;};

struct ppm{
    string magic;
    int width; int height;
    int maxIntensity;
    pixel** data;
    };

void readPPM(/* parameters go here */);
void writePPM(string filePath, const ppm &image);
void verticalFlip(const ppm &source, ppm &result);

int main()
{
    ppm source {"", 0, 0, 0, 0};
    ppm result {"", 0, 0, 0, 0};
    readPPM("blackbuck.ppm", source);
    verticalFlip(source, result);
    writePPM("vertFlip_blackbuck.ppm", result);
    return 0;
}

void readPPM(/* parameters go here */)
{
    // your code here
}

void writePPM(string filePath, const ppm &image)
{
    ofstream output(filePath);
    if(output.fail())
    {
        cout << "Could not open output file " << filePath << "." << endl;
        return;
    }
    output << image.magic << endl;
    output << image.width << " " << image.height << endl;
    output << image.maxIntensity << endl;
    for(int i = 0; i < image.height; i++)
    {
        for(int j = 0; j < image.width; j++)
        {
            output << image.data[i][j].R << " ";
            output << image.data[i][j].G << " ";
            output << image.data[i][j].B << " ";
        }
        output << endl;
    }
    output.close();
}

void verticalFlip(const ppm &source, ppm &result)
{
    result = source;
    result.data = new pixel*[result.height];
    for(int i = 0 ; i < result.height; i++)
    {
        result.data[i] = new pixel[result.width];
    }
    for(int i = 0; i < result.height; i++)
    {
        for(int j = 0; j < result.width; j++)
        {
            result.data[i][j] = source.data[i][source.width-1-j];
        }
    }
}

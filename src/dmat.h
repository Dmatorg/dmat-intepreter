/*
 * DMAT Official Imaging Library
 * Written by ghgltggamer
 *
 * This library is licensed under the terms found in the LICENSE file.
 */

// DMAT Lang version 1.0.1

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"
#include <cmath>
#include <cstring>
#include <iostream>

// Global intensity variables
int Inormal = 128;     // Intensity for normal map
int Iheight = 128;     // Intensity for height map
int Iroughness = 128;  // Intensity for roughness map
int Imetallic = 128;   // Intensity for metallic map

// Function to calculate the intensity of a pixel
float getIntensity(unsigned char r, unsigned char g, unsigned char b) {
    return (r + g + b) / 3.0f / 255.0f;
}

// Function to create an improved normal map from the albedo image
void createNormalMap(unsigned char* albedo, unsigned char* normalMap, int width, int height, int channels) {
    float intensity = static_cast<float>(Inormal);
    for (int y = 1; y < height - 1; ++y) {
        for (int x = 1; x < width - 1; ++x) {
            int index = (y * width + x) * channels;

            float intensityL = getIntensity(albedo[index - channels], albedo[index - channels + 1], albedo[index - channels + 2]);
            float intensityR = getIntensity(albedo[index + channels], albedo[index + channels + 1], albedo[index + channels + 2]);
            float intensityU = getIntensity(albedo[index - width * channels], albedo[index - width * channels + 1], albedo[index - width * channels + 2]);
            float intensityD = getIntensity(albedo[index + width * channels], albedo[index + width * channels + 1], albedo[index + width * channels + 2]);

            float dx = intensityR - intensityL;
            float dy = intensityD - intensityU;
            float dz = intensity / 255.0f;

            float length = sqrt(dx * dx + dy * dy + dz * dz);
            dx /= length;
            dy /= length;
            dz /= length;

            normalMap[index] = static_cast<unsigned char>((dx * 0.5f + 0.5f) * 255);
            normalMap[index + 1] = static_cast<unsigned char>((dy * 0.5f + 0.5f) * 255);
            normalMap[index + 2] = static_cast<unsigned char>((dz * 0.5f + 0.5f) * 255);
        }
    }
}

// Function to create a height map from the albedo image
void createHeightMap(unsigned char* albedo, unsigned char* heightMap, int width, int height, int channels) {
    float intensity = static_cast<float>(Iheight);
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int index = (y * width + x) * channels;
            unsigned char r = albedo[index];
            unsigned char g = albedo[index + 1];
            unsigned char b = albedo[index + 2];

            float pixelIntensity = (r + g + b) / 3.0f;
            heightMap[y * width + x] = static_cast<unsigned char>(pixelIntensity * (intensity / 255.0f));
        }
    }
}

// Function to create a roughness map from the albedo image
void createRoughnessMap(unsigned char* albedo, unsigned char* roughnessMap, int width, int height, int channels) {
    float intensity = static_cast<float>(Iroughness);
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int index = (y * width + x) * channels;
            unsigned char r = albedo[index];
            unsigned char g = albedo[index + 1];
            unsigned char b = albedo[index + 2];

            float pixelIntensity = (r + g + b) / 3.0f;
            roughnessMap[y * width + x] = static_cast<unsigned char>((255 - pixelIntensity) * (intensity / 255.0f)); // Invert for roughness
        }
    }
}

// Function to create a metallic map from the albedo image
void createMetallicMap(unsigned char* albedo, unsigned char* metallicMap, int width, int height, int channels) {
    float intensity = static_cast<float>(Imetallic);
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int index = (y * width + x) * channels;
            unsigned char r = albedo[index];
            unsigned char g = albedo[index + 1];
            unsigned char b = albedo[index + 2];

            float pixelIntensity = (r + g + b) / 3.0f;
            metallicMap[y * width + x] = static_cast<unsigned char>(pixelIntensity * (intensity / 255.0f));
        }
    }
}

// Function to convert an albedo image directly into a normal map
void convertAlbedoToNormalMap(const std::string& inputFilePath, const std::string& outputFilePath) {
    int width, height, channels;
    unsigned char* albedo = stbi_load(inputFilePath.c_str(), &width, &height, &channels, 0);
    if (!albedo) {
        std::cerr << "Failed to load image " << inputFilePath << std::endl;
        return;
    }

    unsigned char* normalMap = new unsigned char[width * height * channels];
    memset(normalMap, 0, width * height * channels);

    createNormalMap(albedo, normalMap, width, height, channels);

    stbi_write_png(outputFilePath.c_str(), width, height, channels, normalMap, width * channels);

    stbi_image_free(albedo);
    delete[] normalMap;

    std::cout << "Normal map generated and saved as " << outputFilePath << std::endl;
}

// Function to process an albedo image into all maps with specified filenames
void DMAT_FINAL_PROCESS(const std::string& albedoImageName, const std::string& normalMapName, const std::string& heightMapName, const std::string& roughnessMapName, const std::string& metallicMapName) {
    int width, height, channels;
    unsigned char* albedo = stbi_load(albedoImageName.c_str(), &width, &height, &channels, 0);
    if (!albedo) {
        std::cerr << "Failed to load image " << albedoImageName << std::endl;
        return;
    }

    unsigned char* normalMap = new unsigned char[width * height * channels];
    unsigned char* heightMap = new unsigned char[width * height];
    unsigned char* roughnessMap = new unsigned char[width * height];
    unsigned char* metallicMap = new unsigned char[width * height];

    memset(normalMap, 0, width * height * channels);
    memset(heightMap, 0, width * height);
    memset(roughnessMap, 0, width * height);
    memset(metallicMap, 0, width * height);

    createNormalMap(albedo, normalMap, width, height, channels);
    createHeightMap(albedo, heightMap, width, height, channels);
    createRoughnessMap(albedo, roughnessMap, width, height, channels);
    createMetallicMap(albedo, metallicMap, width, height, channels);

    stbi_write_png(normalMapName.c_str(), width, height, channels, normalMap, width * channels);
    stbi_write_png(heightMapName.c_str(), width, height, 1, heightMap, width);
    stbi_write_png(roughnessMapName.c_str(), width, height, 1, roughnessMap, width);
    stbi_write_png(metallicMapName.c_str(), width, height, 1, metallicMap, width);

    stbi_image_free(albedo);
    delete[] normalMap;
    delete[] heightMap;
    delete[] roughnessMap;
    delete[] metallicMap;

    std::cout << "All maps generated and saved successfully." << std::endl;
}

/*int main() {
    std::string albedoImageName = "a.png";
    std::string normalMapName = "normal_map.png";
    std::string heightMapName = "height_map.png";
    std::string roughnessMapName = "roughness_map.png";
    std::string metallicMapName = "metallic_map.png";

    // Set intensities as needed
    Inormal = 200;
    Iheight = 150;
    Iroughness = 100;
    Imetallic = 180;

    DMAT_FINAL_PROCESS(albedoImageName, normalMapName, heightMapName, roughnessMapName, metallicMapName);

    // Optionally, you can also convert albedo to normal map directly
    std::string directNormalMapName = "direct_normal_map.png";*/
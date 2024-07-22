<h1>DMAT - Dextel Material (Dextile Material) Domain-Specific Language for Image Processing (Version 1.2)</h1>

    <p>DMAT is a Domain-Specific Language designed for image processing tasks such as generating normal maps, height maps, roughness maps, and metallic maps from an albedo image. This repository contains the source code for the DMAT interpreter and an example of how to use it.</p>

    <h2>Features</h2>
    <ul>
        <li>Generate normal maps from albedo images</li>
        <li>Create height maps from albedo images</li>
        <li>Create roughness maps from albedo images</li>
        <li>Create metallic maps from albedo images</li>
        <li>Set intensity of all different maps with a global variable ranging from 1 to 255</li>
    </ul>

    <h2>Getting Started</h2>

    <h3>Prerequisites</h3>
    <p>Make sure you have the following dependencies installed if you plan to compile the source code:</p>
    <ul>
        <li>C++ compiler (g++ or clang++)</li>
    </ul>

    <h3>Installation</h3>
    <p>You have two options to get started with DMAT:</p>

    <h4>Option 1: Download Precompiled Executable (Linux)</h4>
    <ol>
        <li>Download the precompiled executable from the project page:</li>
        <pre><code>https://dmatorg.github.io/</code></pre>
    </ol>

    <h4>Option 2: Compile from Source</h4>
    <ol>
        <li>Download the source code as a ZIP file:</li>
        <ul>
            <li>Go to the repository page: <a href="https://github.com/Dmatorg/dmat-intepreter/tree/main">https://github.com/Dmatorg/dmat-intepreter/tree/main</a></li>
            <li>Click on the "Code" button and select "Download ZIP".</li>
        </ul>
        <li>Extract the ZIP file:</li>
        <pre><code>unzip dmat-main.zip</code></pre>
        <li>Navigate to the extracted directory:</li>
        <pre><code>cd dmat-main</code></pre>
        <li>Compile the source code:</li>
        <pre><code>g++ -o dmat_compiler dmat_compiler.cpp -std=c++11</code></pre>
    </ol>

    <h3>Usage</h3>
    <p>Create a .dmat file with the following format:</p>
    <pre><code>
DMAT_ALBEDO: example_albedo.png
DMAT_NORMALS: example_normal_map.png
DMAT_HEIGHTS: example_height_map.png
DMAT_ROUGHNESSS: example_roughness_map.png
DMAT_METALICS: example_metallic_map.png
INORMAL: 128
IHEIGHT: 128
IROUGHNESS: 128
IMETALIC: 128
EXIT&BUILD
    </code></pre>
    <p>Run the DMAT compiler:</p>
    <pre><code>./dmat_compiler</code></pre>
    <p>or if you downloaded the precompiled executable:</p>
    <pre><code>./dmat_compiler.out</code></pre>
    <p>Follow the prompts to enter the path to your .dmat file. The output images will be generated and saved with the specified filenames.</p>

    <h2>Example</h2>
    <p>Here is an example .dmat file:</p>
    <pre><code>
DMAT_ALBEDO: albedo.png
DMAT_NORMALS: normal_map.png
DMAT_HEIGHTS: height_map.png
DMAT_ROUGHNESSS: roughness_map.png
DMAT_METALICS: metallic_map.png
INORMAL: 128
IHEIGHT: 128
IROUGHNESS: 128
IMETALIC: 128
EXIT&BUILD
    </code></pre>

    <hr>

    <h2>DMAT Language Tutorial</h2>
    <p>DMAT Lang is powerful for designing PBR from Albedo and for doing this you need to be familiar with DMAT Lang Syntax!</p>

    <h3>Syntax - Assignment Based</h3>
    <p>Assignment Based Syntax is the custom DMAT syntax where you need to assign some key values to DMAT in order to build your materials</p>

    <h3>Params</h3>
    <ul>
        <li><b>DMAT_ALBEDO:</b> (Used to load the albedo image into the memory buffer. This image will be processed for making materials)</li><br>
        <li><b>DMAT_NORMALS:</b> (Used to load the normal map file name into the memory buffer. The normal map will be created with the given file name)</li><br>
        <li><b>DMAT_HEIGHTS:</b> (Used to load the height map file name into the memory buffer. The height map will be created with the given file name)</li><br>
        <li><b>DMAT_ROUGHNESSS:</b> (Used to load the roughness map file name into the memory buffer. The roughness map will be created with the given file name)</li><br>
        <li><b>DMAT_METALICS:</b> (Used to load the metallic map file name into the memory buffer. The metallic map will be created with the given file name)</li><br>
        <li><b>INORMAL:</b> (Used to define the intensity of the normal map. This sets the pixel intensity of the normal map, ranging from 1 to 255)</li><br>
        <li><b>IHEIGHT:</b> (Used to define the intensity of the height map. This sets the pixel intensity of the height map, ranging from 1 to 255)</li><br>
        <li><b>IROUGHNESS:</b> (Used to define the intensity of the roughness map. This sets the pixel intensity of the roughness map, ranging from 1 to 255)</li><br>
        <li><b>IMETALIC:</b> (Used to define the intensity of the metallic map. This sets the pixel intensity of the metallic map, ranging from 1 to 255)</li><br>
    </ul>

    <pre><code>Note: DMAT is case and indentation sensitive, meaning Upper case must be Upper case and Lower case must be lower case. Don't add spaces between params like "DMAT_ALBEDO: a.png". DMAT will count the space between : and a.png as file name and it will return. The correct way is "DMAT_ALBEDO:a.png"</code></pre>

    <h2>Contributing</h2>
    <p>Contributions are welcome! Please feel free to submit a pull request or open an issue.</p>

    <h2>License</h2>
    <p>This project is licensed under the MIT License.</p>

    <h2>Contact</h2>
    <p>For any questions or inquiries, please contact <a href="mailto:dmatorg@gmail.com">dmatorg@gmail.com</a>.</p>

    <p>Visit the project page: <a href="https://dmatorg.github.io/">dmatorg.github.io</a></p>

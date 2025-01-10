This implementation applies the following algorithms: **marching_squares**, **resize**, and **init_contur** on an image in the **P3** format. The program waits for commands typed in the standard input (STDIN), such as:

- `WRITE`
- `READ`
- `RESIZE`
- `INIT_CONTUR`
- `GRID`
- `MARCH`

The image is defined in a nested structure containing the following information:

- Maximum value of the pixels
- Pixel colors
- Image format
- Number of columns and rows of pixels

---

## Commands and Functions

### **READ()**
This function reads values from the STDIN that represent the image.

- **First call**: Allocates the necessary space for the image and reads the values.
- **Subsequent calls**: Frees the space allocated for the previous image, reallocates space for the new image, and reads the values.

---

### **WRITE()**
This function writes the image details, including:

- Format
- Maximum value of the pixels
- Number of rows and columns of pixels
- Pixel values in the format `(R, G, B)`

---

### **INIT_CONTUR()**
This function generates the patterns required for the marching squares algorithm.

1. Initializes a lookup table for each image.
2. Creates a vector of images that retains values from the lookup table.
3. Ensures the pixel values are uniform for `(R, G, B)`.

---

### **GRID()**
This function creates a grid for the image stored in memory. The grid dimension is determined by the formula:

\[
\text{Grid Dimension} = \frac{N}{4} + 1
\]

1. Calls `average_color_pixel()` to create a matrix of pixel intensities.
2. For each node in the grid:
   - Calculates the average intensity in a cross pattern.
   - Sets the node value to:
     - `1` if the average ≤ 200 (threshold)
     - `0` if the average > 200
3. Steps through the matrix with a step size of `4`, processing pixel averages.
4. For edge pixels, only includes existing pixels.

---

### **MARCH()**
Implements the marching squares algorithm:

1. Calls `GRID` and `INIT_CONTUR` to initialize the required data.
2. Traverses the grid to determine the pattern for each position.
3. Reconstructs the image using patterns generated by `INIT_CONTUR`.
4. Replaces the old image with the newly reconstructed image.

---

### **EXIT()**
This command exits the program and deallocates all resources used during execution.

---
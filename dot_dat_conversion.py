import pandas as pd
import numpy as np

binary_file_path = r"C:\Opes files\2023-09-21_12-19-07\Record Node 102\experiment1\recording1\continuous\OE_FPGA_Acquisition_Board-100.Rhythm Data\continuous.dat"

# Define the data type (e.g., np.int16 for 16-bit data)
dtype = np.int16

# Read the binary data
try:
    with open(binary_file_path, "rb") as binary_file:
        binary_data = binary_file.read()

        # Assuming little-endian byte order
        data = np.frombuffer(binary_data, dtype=dtype)

        # Create a DataFrame with a single column 'Voltage' from the data
        df = pd.DataFrame({'Voltage': data})

        # Save the DataFrame to a CSV file
        csv_file_path = r"C:\Opes files\2023-09-21_12-19-07\Record Node 102\experiment1\recording1\continuous\OE_FPGA_Acquisition_Board-100.Rhythm Data\continuous.csv"  # Specify the path to save the CSV file
        df.to_csv(csv_file_path, index=False)

        print(f"CSV file saved at: {csv_file_path}")
except FileNotFoundError:
    print(f"File not found: {binary_file_path}")

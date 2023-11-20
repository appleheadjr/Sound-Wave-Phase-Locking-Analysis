import numpy as np
import pandas as pd

# Load the data from the .npy file
loaded_data = np.load("C:\Opes files\2023-09-21_12-19-07\Record Node 102\experiment1\recording1\continuous\OE_FPGA_Acquisition_Board-100.Rhythm Data\timestamps.npy")

# Convert the NumPy array to a Pandas DataFrame
df = pd.DataFrame(loaded_data)

# Save the DataFrame to a CSV file
df.to_csv("timestamps.csv", index=False, header=False)  # You can adjust parameters as needed

import csv

# Read data from the text file
file_path = r"C:\Opes files\MarkerFile-bst.txt"

with open(file_path, 'r') as file:
    text_data = file.read()

# Split the text data into lines
lines = text_data.split('\n')

# Create a CSV file in the specified location and write the header
output_file_path = r"C:\Opes files\output2.csv"
with open(output_file_path, 'w', newline='') as csvfile:
    csv_writer = csv.writer(csvfile)
    csv_writer.writerow(['Channel', 'Timestamp', 'Cluster'])

    # Write each line to the CSV file, excluding rows with |0| clusters
    for line in lines:
        parts = line.split(', ')

        # Check if the line has enough elements
        if len(parts) >= 2:
            channel_info = parts[0].split(' ')
            timestamp = float(parts[1])
            cluster_info = channel_info[-1] if '|' in channel_info[-1] else '|0|'

            # Skip rows with |0| clusters
            if cluster_info != '|0|':
                csv_writer.writerow([channel_info[-2], timestamp, cluster_info])

print(f"CSV file saved to: {output_file_path}")

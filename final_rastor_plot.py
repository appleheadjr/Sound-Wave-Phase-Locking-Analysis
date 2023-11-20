import pandas as pd
import matplotlib.pyplot as plt

# Read the grouped CSV file
grouped_file_path = r"C:\Opes files\output_grouped.csv"
df = pd.read_csv(grouped_file_path)

# Get unique clusters
unique_clusters = df['Cluster'].unique()

# Define a color map for each cluster
color_map = plt.cm.get_cmap('tab10', len(unique_clusters))

# Plotting the raster plot
for i, cluster in enumerate(unique_clusters):
    group = df[df['Cluster'] == cluster]
    plt.eventplot(group['Timestamp'], orientation='horizontal', label=f'Cluster {cluster}', linewidths=2, color=color_map(i))

plt.xlabel('Time')
plt.ylabel('Clusters')
plt.title('Raster Plot of Clusters over Time')
plt.legend()

# Set the x-axis limits for zooming up to 30 seconds
plt.xlim(0, 2)

custom_xticks = [0, 0.25,0.3, 0.5, 1, 1.3, 1.5, 1.75,2]
plt.xticks(custom_xticks)

plt.show()

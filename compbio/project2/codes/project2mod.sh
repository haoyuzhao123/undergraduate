#! /bin/bash
python generate_data.py
python preprocessing.py

mkdir first_clustering
mkdir second_clustering
mkdir third_clustering

python first_cluster.py
python second_cluster.py
python third_cluster.py

mkdir rec_clustering
mv ./first_clustering ./rec1_first_clustering
mv ./second_clustering ./rec1_second_clustering
mv ./third_clustering ./rec1_third_clustering

mv ./rec1* ./rec_clustering

mkdir second_clustering
mkdir third_clustering

python second_cluster.py
python third_cluster.py

mv ./second_clustering ./rec2_second_clustering
mv ./third_clustering ./rec2_third_clustering

mv ./rec2* ./rec_clustering

mkdir second_clustering
mkdir third_clustering

python second_cluster.py
python third_cluster.py

mv ./second_clustering ./rec3_second_clustering
mv ./third_clustering ./rec3_third_clustering

mv ./rec3* ./rec_clustering



N=1000
echo $N
for ((i=0; i<N; i++)); do
  echo $((RANDOM % 100 + 1))
done

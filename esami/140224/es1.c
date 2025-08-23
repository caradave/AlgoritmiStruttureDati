int *rotVet(int *v, int n, int d){
  int *vAus = malloc(n*sizeof(int));

  for(int i=0; i<n; i++){
    if(i<=n-d-1)
      vAus[i+d] = v[i];
    else
      vAus[n-d-i] = v[i];
  }

  return vAus;
}

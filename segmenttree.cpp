typedef long long ll;
#define mid ((left + right) >> 1)
vector<int> t[400001];

int build (int i,int left, int right){
   if (left == right){
    t[i] = a[l];
    return t[i];
   }
   int leftsum = build(i*2, left, mid);
   int rightsum = build(i*2+1, mid+1, right);
   t[i] = leftsum + rightsum;
   return t[i];
}

int find(int i,int l,int r,int left,int right){
    if (l>r || l==0 && r==0)return 0;
   if (l==left && r==right)return t[i];
  if (r<=mid){
    return find(i*2, l,r,left,mid);
    }
  else  if (l>mid)return find(i*2+1, l,r,mid+1, right);
  else {
    int leftsum = find(i*2, l,mid, left, mid);
    int rightsum = find(i*2+1,mid+1,r, mid+1, right);
    return leftsum + rightsum;
  }

}

int update (int i,int l,int r,int left, int right, int value){
   if (l>r)return 0;
if (left==l && right==r)
    {
        t[i] = value;
        a[i] = value;
        return t[i];
    }

    if (r<=mid)
        update(i<<1,l,r,left,mid,value);
    else if (l>mid) update((i<<1)|1,l,r,mid+1,right,value);
    else {
        update(i<<1, l,mid, left,mid,value);
        update(i*2+1, mid+1,r,mid+1,right,value);
    }
    t[i] = t[i*2] + t[i*2+1];
    return t[i];

}

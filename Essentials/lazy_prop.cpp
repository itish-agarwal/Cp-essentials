//LAZY PROPAGATION

#include <bits/stdc++.h>

using namespace std;

struct node {
	int sum, maxr, lazy;
	node() {
		sum = maxr = lazy = 0;
	}
};

node merge(node a, node b) {
	node ans;
	ans.sum = a.sum + b.sum;
	ans.maxr = max(a.maxr, b.maxr);
	return ans;
}

node t[400400];

void push(int index, int l, int r) {
	if(t[index].lazy > 0) {
		t[index].sum = t[index].lazy*(r-l+1);
		t[index].maxr = t[index].lazy;
		if(l!=r) {
			t[index<<1].lazy = t[index<<1|1].lazy = t[index].lazy;
		}
		t[index].lazy = 0;
	}
	return;
}

void update(int index, int l, int r, int lq, int rq, int val) {
	push(index, l, r);
	if(lq>r || l>rq) {
		return;
	}
	if(lq<=l && r<=rq) {
		t[index].lazy = val;
		push(index, l, r);
		return;
	}
	int mid = (l+r)/2;
	update(2*index, l, mid, lq, rq, val);
	update(2*index+1, mid+1, r, lq, rq, val);
	t[index] = merge(t[2*index], t[2*index+1]);
}

node query(int index, int l, int r, int lq, int rq) {
	push(index, l, r);
	if(lq>r || l>rq) {
		return node();
	}
	if(lq<=l && r<=rq) {
		return t[index];
	}
	int mid = (l+r)/2;
	return merge(query(index<<1, l, mid, lq, rq), query(index<<1|1, mid+1, r, lq, rq));
}
void __print(auto x) {cerr << x;}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int x = 5;
	__print(x);
	return 0;
}

	
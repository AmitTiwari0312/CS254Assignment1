#include <bits/stdc++.h>
using namespace std;

double findMedian(int* a, int n, int* b, int m) {

	int index1 = 0, index2 = n, i, j, median;

	while (index1 <= index2) {
		i = (index1 + index2) / 2;
		j = ((n + m + 1) / 2) - i;

		if (j < 0) {
			index2 = i - 1;
			continue;
		}

		if (i < n && j > 0 && b[j - 1] > a[i])
			index1 = i + 1;

		else if (i > 0 && j < m && b[j] < a[i - 1])
			index2 = i - 1;

		else {
			if (i == 0) median = b[j - 1];
			else if (j == 0) median = a[i - 1];
			else median = max(a[i - 1], b[j - 1]);
			break;
		}
	}

	if ((n + m) % 2 == 1)
		return (double)median;

	if (i == n)
		return (median + b[j]) / 2.0;

	if (j == m)
		return (median + a[i]) / 2.0;

	return (median + min(a[i], b[j])) / 2.0;
}

int main() {

    ifstream iF("input.txt");
    ofstream oF("output.txt");

    int t; iF >> t;
    while (t--) {
		int n; iF >> n;
		int m; iF >> m;
		int a[n],b[m];
		for (int i=0; i<n; i++) iF >> a[i];
		for (int i=0; i<m; i++) iF >> b[i];
		
		oF << "The median is : ";
		if (n < m) oF << findMedian(a, n, b, m);
		else oF << findMedian(b, m, a, n);
		oF << endl;

	}

    iF.close();
    oF.close();

	return 0;
}

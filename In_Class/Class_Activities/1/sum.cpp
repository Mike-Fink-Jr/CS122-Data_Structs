// This is a simple implementation file, for demonstrating
// multiple source-file compilation.  This is a very simple
// function here (with a couple small bugs in it) that will
// be linked with multiple client applications.

int sumArray( int data[], int size )
{
    int sum;

    for (int i = 0; i <= size; i++ )
	sum = sum + data[i];
    return sum;
}

Let’s launch two threads and see if they actually run in parallel:

Outcome: two threads count to dmesg from 0 to 9 in parallel.

Each line has output of form:

<thread_id> <count>

Possible very likely outcome:

1 0
2 0
1 1
2 1
1 2
2 2
1 3
2 3

The threads almost always interleaved nicely, thus confirming that they are actually running in parallel.



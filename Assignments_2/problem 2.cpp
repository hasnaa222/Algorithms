#include <iostream>
#include <cmath>
using namespace std;

///Ackermann function (Basic version):
long long Ack(int m ,int n);
int main()
{
   cout<<Ack(3,3);

    return 0;
}
long long Ack(int m ,int n)
{
    if(m==0)
    {
        return n+=1;
    }
    else if(m>0 && n==0)
    {
        return Ack(m-1,1);

    }

    else if(m>0&& n>0)
    {
        return Ack(m-1,Ack(m,n-1));
    }

}
///1.Describe why the base Ackermann function is so heavy to comput :
/*Because ts value grows rapidly, even for small inputs. For example, A(4, 2) is an integer of 19,729 decimal digits[3] (equivalent to 265536−3, or 22222−3).*/


///2.Write an optimization to make it’s calculation more efficient and possible for arguments starting Ack(4, 1) and above

/*By unraveling the ackerman algorithm a few steps, I got ackerman(4,4) in
terms of ackerman(3, ... )

ack(4,4) = ack(3, ack(4,3))

ack(4,3) = ack(3, ack(4,2))

ack(4,2) = ack(3, ack(4,1))

ack(4,1) = ack(3, ack(4,0))

ack(4,0) = ack(3,1)


By transitivity,

ack(4,4) = ack(3, ack(3, ack(3, ack(3, ack(3,1)))))


By empirical investigation, [*]

ack(3,j) = 2^(j+3) - 3

(also, if anyone is interested, ack(1,j) = 2 + j and ack(2,j) = 2j + 1)

By applying the formula for ack(3,j),

ack(4,4) = ack(3, ack(3, ack(3, ack(3,13))))
	 = ack(3, ack(3, ack(3,65533)))

At this point my calculator cannot figure any higher, so we can do this
symbolically.

	 = ack(3, ack(3, (2^(65533 + 3) - 3)))
	 = ack(3, (2^(2^65536 - 3 + 3) -3))
	 = 2^(2^(2^65536)) - 3

And this is a really big number and may reduce to something simple,
but at this point my head is starting to hurt
I discovered the formula for ack(3,j) by writing a C program that figured
with 64 bit types.  (Looking at the result, 64 bits isn't even close
to enough.)  However, it kept segmentation faulting, which meant
that it was probably accessing memory that it didn't own.

This led me to modify my ackerman function to print out what stage it was
at so I knew when it errored.  (I.e. after each time ackerman called
itself recursively, it would print out i, j, and ack(i,j) before returning
a value.)  Then it occurred to me that I could cache the value for
ack(i,j)  for various values of i and j, so that once I had figured
ack(i,j) for a particular i and j, I would remember it and not do it
again.

I then realized that I could save more time by taking the partial results
from previous unsuccessful attempts and preload the cache with these
values. (By simply assigning values to some 2-d array, which was my cache,
indexed by i and j.)

In the process of writing some 'perl' scripts that would format the data
into 'C' code (i.e. assigments to the 2-d cache), I saw a pattern, where
ack(3,j) equals ack(3,j - 1) + 2^(j+2), with j > 0 (and with ack(3,0) = 5
= 1 + 2^2).

(I suppose this has the makings of an inductive proof.)

By trying to eliminate the recursive call to ack(3,j - 1), I came up with

ack(3,j) = 1 + 2^2 + 2^3 + 2^4 + ... + 2^(j + 2)

	 = 1 + 2^2 * (2^0 + 2^1 +2^2 + ... + 2^j)

	 / magic series stuff here /

	 = 1 + 2^2 * (2^(j + 1) - 1)

	 = 1 + 2^(j + 3) - 2^2

	 = 2^(j + 3) -3

     ack(3,j) = 2^(j + 3) - 3

I realize this isn't a formal proof, but it's good enough for government
work.
*/

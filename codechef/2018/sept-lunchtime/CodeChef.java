import java.io.*;
import java.util.*;
import java.lang.*;
class Reader1
{
	BufferedReader bf;

	StringTokenizer sc;
	Reader1()
	{
		bf=new BufferedReader(new InputStreamReader(System.in));
	}
	String string() throws NullPointerException
	{

		while(sc==null || !sc.hasMoreElements())
		{
			try
			{
				sc=new StringTokenizer(bf.readLine());
			}
			catch(IOException e)
			{

			}
		}
		return(sc.nextToken());
	}
	int dataInt()
	{
		return(Integer.parseInt(string()));
	}
	long dataLong()
	{
		return(Long.parseLong(string()));
	}

}

class CodeChef
{
	public static void main(String[] ar) throws Exception
	{
		Reader1 reader=new Reader1();

		int t,u=0;
		t=reader.dataInt();
		while(t-->0)
		{
			int n,q,l,r;
			long x,y,z,c,p=0;
			n=reader.dataInt();
			q=reader.dataInt();

			long a[]=new long[n];
			long b[]=new long[n];

			for(int i=0;i<n;i++)
			a[i]=reader.dataLong();

			for(int i=0;i<n;i++)
			b[i]=reader.dataLong();
			for(int j=0;j<n;j++)
				{
					if(a[j]==b[j])
					p++;

				}

			for(int i=0;i<q;i++)
			{



				u++;
				x=reader.dataLong();
				y=reader.dataLong();
				z=reader.dataLong();
				Long l1=x^p;
				Long r1=y^p;
				l=l1.intValue();
				r=r1.intValue();
				c=z^p;
					//System.out.println(r+"hii"+l+""+c);
                try
				{   while(l<=r)
				    {
					    a[l-1]=c;
					    l++;
			    	}
				}
				catch(ArrayIndexOutOfBoundsException ie)
				{
				    ie.printStackTrace();
				}
				p=0;
				for(int j=0;j<n;j++)
				{
					if(a[j]==b[j])
					p++;

				}

					System.out.println(p);
			}


		}
	}
}

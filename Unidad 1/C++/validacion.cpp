<pre><div class="text_to_html">#include &lt;iostream&gt;
#include &lt;cstdlib&gt;
#include &lt;cstdio&gt;
#include &lt;cstring&gt;

using namespace std;


int main(){

	int edad;
	char letra;

	/*
	cout&lt;&lt;&quot;Ingrese una edad mayor o igual que 18: &quot;;
	cin&gt;&gt;edad;
	while(edad&lt;18){
		cout&lt;&lt;&quot;La edad ingresada NO es valida, por favor, ingrese nuevamente...&quot;&lt;&lt;endl;
		cout&lt;&lt;&quot;Ingrese una edad mayor o igual que 18: &quot;;
		cin&gt;&gt;edad;
	}
	*/
	
	do{
		cout&lt;&lt;&quot;Ingrese una edad mayor o igual que 18: &quot;;
		cin&gt;&gt;edad;	
	}while(edad&lt;=17 &amp;&amp; edad&gt;=65);
	
	
	cout&lt;&lt;&quot;La edad ingresada es: &quot;&lt;&lt;edad&lt;&lt;endl;
	
	
}

</div></pre>
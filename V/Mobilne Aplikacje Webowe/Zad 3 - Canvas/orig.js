var q, qg;
var stan=0;
var comal=0;
var x1,y1,x2,y2,kw=0,grl=1,rr=0;
var kolory=new Array("rgb(0,0,0)","rgb(255,0,0)","rgb(0,255,0)","rgb(0,0,255)","rgb(255,255,0)","rgb(0,255,255)","rgb(255,0,255)","rgb(255,255,255)","rgb(128,128,128)");
var koloryx=new Array(0,0,0,255,0,0,0,255,0,0,0,255,255,255,0,0,255,255,255,0,255,255,255,255,128,128,128);
var grubsr=new Array;
var ryspix, rys;
var praca=0;

function ustawKolory()
{
	var lista,i;
	lista=$('pkolo').getElementsByTagName('td');
	for(i=0; i<9; i++)
	{
		lista[i].style.backgroundColor=kolory[i];
		lista[i].onclick=wybierz;
		lista[i].nr=i;
	}
}


function ustawGrubLinii()
{
	var t,y,k,kk;
  t=$('cgr').getContext('2d');
  t.lineCap="round"
  
  t.strokeStyle="rgb(50,50,50)";
  
  y=5;
  for(k=0; k<11; k++)
  {
	  t.beginPath();
	  t.lineWidth=k+k+1;
	  kk=2*k*k+5*k+5;
	  grubsr[k]=kk;
	  t.moveTo(10+k,kk);
	 	t.lineTo(150-k,kk);
	 	t.stroke();		
  }
  
  
}

function wybierzgr(e)
{
	var yy,gran;	
	yy=e.pageY-180-5;
	
	for(k=0; k<11; k++)
	{
		gran=grubsr[k]+k;
		if(yy<gran) 
		{
			grl=k+k+1; break;
		}
	}
	
	$('info').innerHTML=grl;
}

function wProstok(x,y,x1,y1,x2,y2)
{
	if(x1<x && x<x2 && y1<y && y<y2) return true; else return false;
}

function wybnarz(e)
{
	var xx,yy;
	xx=e.pageX-1060;
	yy=e.pageY-85;
	if(wProstok(xx,yy,13,15 ,105, 51 ))  { comal=0; $('obraznarz').src='narzedzia1.png';}else
	if(wProstok(xx,yy,13,69 ,105,102 ))  { comal=1; $('obraznarz').src='narzedzia2.png';}else
	if(wProstok(xx,yy,13,123,105,192 ))  { comal=2; $('obraznarz').src='narzedzia3.png';}else
	if(wProstok(xx,yy,13,216,105,283 ))  { comal=3; $('obraznarz').src='narzedzia4.png';}else
	if(wProstok(xx,yy,13,313,120,385 ))  { comal=4; $('obraznarz').src='narzedzia5.png';}
	
	
	$('info').innerHTML=xx+','+yy+'/'+comal;
}

function wybierz()
{
	kw=this.nr;
	
}

function narysujPix( x, y)
{
	
    var xy = 4*(y*800+x);
    ryspix[xy  ] = koloryx[3*kw];
    ryspix[xy+1] = koloryx[3*kw+1];
    ryspix[xy+2] = koloryx[3*kw+2];
    ryspix[xy+3] = Math.floor(Math.random()*256);
}


function wykonaj()
{
	q=$('can').getContext('2d');
	qg=$('cang').getContext('2d');
	q.lineCap="round";
	qg.lineCap="round";
	
	q.fillStyle="rgb(255,255,255)";
	q.fillRect(0,0,800,400);
	q.fillStyle="blue";
  q.font="30px 'Segoe Script', Mistal, serif";
  q.textAlign="right";
  q.fillText("Marek Żabka",795,395);
  
  
//  for(xxx=0; xxx<300; xxx++)
//  for(yyy=0; yyy<200; yyy++)
//	narysujPix(xxx,yyy);
//  
//	q.putImageData(rys, 0, 0);

	ustawKolory();
	ustawGrubLinii();
	stan=0;
}


function $(n) {return document.getElementById(n);}

function rysstart(e)
{	
	x1=e.pageX-10;
	y1=e.pageY-80;
	
	stan=1;
}

function rysowanie1(e)
{
	var xx,yy;
	xx=e.pageX-10;
	yy=e.pageY-80;
	if(stan==1) 
	{
		if(comal==1)
		{
			qg.clearRect(0,0,800,400);
			qg.beginPath();
			qg.strokeStyle=kolory[kw];
			qg.lineWidth=grl;
			qg.moveTo(x1,y1);
			qg.lineTo(xx,yy);
			qg.stroke();
			x2=xx;
			y2=yy;
		}
		else
		if(comal==0)
		{
			qg.clearRect(0,0,800,400);
			q.beginPath();
			q.lineWidth=grl;
			q.strokeStyle=kolory[kw];
			q.moveTo(x1,y1);
			q.lineTo(xx,yy);
			q.stroke();		
			x1=xx;
			y1=yy;
		}
		else
		if(comal==2)
		{
			rr=Math.sqrt((x1-xx)*(x1-xx)+(y1-yy)*(y1-yy));			
			qg.clearRect(0,0,800,400);
			qg.beginPath();
			qg.strokeStyle=kolory[kw];
			qg.lineWidth=grl;
			qg.arc(x1,y1,rr,0,7,false);
			qg.stroke();			
		}
		else
		if(comal==3)
		{
			qg.clearRect(0,0,800,400);
			qg.strokeStyle=kolory[kw];
			qg.lineWidth=grl;
			x2=xx;
			y2=yy;
			qg.strokeRect(x1,y1,x2-x1,y2-y1);
		}
		if(comal==4)
		{
 			qg.clearRect(0,0,800,400);
			rys = q.getImageData(0, 0, 800,400);
  			ryspix = rys.data;
			szer=grl*2;
			szer2=szer*szer;
			for(xt=-szer; xt<=szer; xt++)
			for(yt=-szer; yt<=szer; yt++)
			if(xt*xt+yt*yt<szer2 && Math.random()<0.2)
			{
				narysujPix( xx+xt, yy+yt)
			}
			q.putImageData(rys, 0, 0);
		}
		
	}
	
	
	$('info').innerHTML=xx+","+yy+','+rr;
}

function namaluj()
{
	stan=0;
	
	if(comal==1)
	{
		q.beginPath();
		q.strokeStyle=kolory[kw];
		q.lineWidth=grl;
		q.moveTo(x1,y1);
		q.lineTo(x2,y2);
		q.stroke();
	}
	else
	if(comal==2)
	{
		q.beginPath();
		q.strokeStyle=kolory[kw];
		q.lineWidth=grl;		
		q.arc(x1,y1,rr,0,7,false);
		q.stroke();
	}
	else
	if(comal==3)
	{
		q.strokeStyle=kolory[kw];
		q.lineWidth=grl;
		q.strokeRect(x1,y1,x2-x1,y2-y1);
	}

}

var masW = [[-1,1,-1],[1,1,1],[-1,1,-1]];
var masE = [[2,1,1],[0,0,-1],[-1,-1,-1]];
var masU = [[1/3,1/3,1/3],[1/3,1/3,1/3],[1/3,1/3,1/3]];
var masX = [[0,-1,-2],[1,1,-1],[2,1,-2]];


function filrt(maska)
{
	if(praca>0) return;
	praca++;
	setTimeout(filrtuj,10,maska);	
}

function koniecfiltr()
{
	praca--;
}

function negacja()
{
	qg.clearRect(0,0,800,400);
	rys = q.getImageData(0, 0, 800,400);
	ryspix = rys.data;
	wielkosc=800*400*4;
	
	
	for(y=0; y<400; y++)
	for(x=0; x<800; x++)	
	{
		var xy = 4*(y*800+x);
		ryspix[xy  ]=255-ryspix[xy  ];
		ryspix[xy+1]=255-ryspix[xy+1];
		ryspix[xy+2]=255-ryspix[xy+2];
		ryspix[xy+3]=255;
	}
	
	q.putImageData(rys, 0, 0);
	
}

function filrtuj(maska)
{
	qg.clearRect(0,0,800,400);
	//alert(maska);
	rys = q.getImageData(0, 0, 800,400);
	ryspix1 = rys.data;
	ryspix=new Array;
	var i;
	wielkosc=800*400*4;
	for(i=0; i<wielkosc; i++)
	ryspix[i]=ryspix1[i];
	
	var xy=0;
	rr=[[0,0,0],[0,0,0],[0,0,0]];
	gg=[[0,0,0],[0,0,0],[0,0,0]];
	bb=[[0,0,0],[0,0,0],[0,0,0]];
	
	for(y=1; y<399; y++)
	for(x=1; x<799; x++)	
	{
    var xy = 4*(y*800+x);
    
    rr[0][0]=ryspix[xy  -3204];
    gg[0][0]=ryspix[xy+1-3204];
    bb[0][0]=ryspix[xy+2-3204];
    
    rr[0][1]=ryspix[xy  -3200];
    gg[0][1]=ryspix[xy+1-3200];
    bb[0][1]=ryspix[xy+2-3200];
    
    rr[0][2]=ryspix[xy  -3200+4];
    gg[0][2]=ryspix[xy+1-3200+4];
    bb[0][2]=ryspix[xy+2-3200+4];
    
    rr[1][0]=ryspix[xy  -4];
    gg[1][0]=ryspix[xy+1-4];
    bb[1][0]=ryspix[xy+2-4];
           
    rr[1][1]=ryspix[xy  ];
    gg[1][1]=ryspix[xy+1];
    bb[1][1]=ryspix[xy+2];
           
    rr[1][2]=ryspix[xy  +4];
    gg[1][2]=ryspix[xy+1+4];
    bb[1][2]=ryspix[xy+2+4];
    		
    rr[2][0]=ryspix[xy  +3200-4];
    gg[2][0]=ryspix[xy+1+3200-4];
    bb[2][0]=ryspix[xy+2+3200-4];
    
    rr[2][1]=ryspix[xy  +3200];
    gg[2][1]=ryspix[xy+1+3200];
    bb[2][1]=ryspix[xy+2+3200];
           
    rr[2][2]=ryspix[xy  +3200+4];
    gg[2][2]=ryspix[xy+1+3200+4];
    bb[2][2]=ryspix[xy+2+3200+4];
    
    rrx=0;
    ggx=0;
    bbx=0;
    for(dx=0; dx<3; dx++)
		for(dy=0; dy<3; dy++)
		{
			rrx+=rr[dx][dy]*maska[dx][dy];
			ggx+=gg[dx][dy]*maska[dx][dy];
			bbx+=bb[dx][dy]*maska[dx][dy];
		}
		rrx=Math.floor(rrx);
		if(rrx<0) rrx=0; else if(rrx>255) rrx=255;
		ggx=Math.floor(ggx);
		if(ggx<0) ggx=0; else if(ggx>255) ggx=255;
		bbx=Math.floor(bbx);
		if(bbx<0) bbx=0; else if(bbx>255) bbx=255;
		
		//	$('info1').innerHTML+="("+rrx+","+rrx+","+ggx+") ";
		
		ryspix1[xy  ]=rrx;
		ryspix1[xy+1]=ggx;
		ryspix1[xy+2]=bbx;
    	ryspix1[xy+3]=255;
	}
	
	q.putImageData(rys, 0, 0);
	setTimeout(koniecfiltr,10);	
	
}

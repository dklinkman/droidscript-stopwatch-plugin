/*

Stopwatch Library
Code Author by: Nelson Tengkiat

Stopwatch version history
1.00 dated: pre 2016
- initial code not yet plugin
1.10 dated: jan 25, 2016
- initial creation of plugin
- not release to public
- added GetVersion(), Help();
- added int addZero(i);
- added pub Help(), Start(), Stop(), Time(option)
1.11 dated: jan 30, 2016
- added help function
- edited stopwatch example program
1.12 dated: jan 31, 2016
- edited stopwatch example program
- initialize stopwatch value to 0

todo: add laps

*/


// ******************************
// * Library Creation
// ******************************
// stopwatch script
app.CreateStopwatch = function() { return new sWatch();}


// ******************************
// * Stopwatch functions
// ******************************
// show time difference on the stopwatch
// option - milli (for accuracy)
function sWatch() {
	//app.SetDebugEnabled(false); // disable debug
	
	// ******************************
	// * global vars
	// ******************************
	// stopwatch global var
	var o_sw = {
		// code version
		"ver": '1.12',
		"start": 0,
		"stop": 0,
		"time": 0
	}
	
	var shelp=
	  'function StopWatch()\n\n'+
	  'methods\n'+
	  '  Start() - start the watch\n'+
	  '  Stop() - stop the watch\n'+
	  '  Time() - time diffrence\n';
	
	
	// ******************************
    // * Get / Show version
    // ******************************
	// return the version number
	this.GetVersion = function () { return o_sw.ver }
	
	// show version on screen
	this.ShowVersion = function () {
		ss='sWatch ver '+this.GetVersion();
		app.ShowPopup(ss,'bottom');
	}
	

	// ******************************
    // * Internal functions
    // ******************************
	
	// pad zero in front if less than 2 char
	addZero = function (i) {
		if (i < 10) { i = "0" + i; }
		return i
	} // function addZero(i)
	
	// ******************************
    // * Public functions
    // ******************************
    
	// give the help screen
	this.Help = function () { alert(shelp); }

	// start the stopwatch. save ticks
	this.Start = function () {
		app.SetDebugEnabled(false); // disable debug
		o_sw.start=new Date().getTime();
		app.SetDebugEnabled(true); // re-enable debug
	}

	// stop the stopwatch
	this.Stop = function () {
		app.SetDebugEnabled(false); // disable debug
		o_sw.stop=new Date().getTime();
		o_sw.time=o_sw.stop-o_sw.start;
		app.SetDebugEnabled(true); // re-enable debug
	}

	// show time difference on the stopwatch
	// option - milli (for accuracy)
	this.Time = function (option) {
		app.SetDebugEnabled(false); // disable debug
		var days=hrs=mins=secs=milli=0;
		var str=""; unt=tmp=0;
		var lap=o_sw.time;

		// days
		tmp=lap/86400000;
		days=Math.floor(tmp);
		lap-=days*86400000;
		if (days!="00") unt++;

		// hours
		tmp=lap/3600000;
		hrs=addZero(Math.floor(tmp));
		lap-=hrs*3600000;
		if (hrs!="00") unt++;

		// minutes
		tmp=lap/60000;
		mins=addZero(Math.floor(tmp));
		lap-=mins*60000;
		if (mins!="00") unt++;

		// seconds
		tmp=lap/1000;
		secs=addZero(Math.floor(tmp));
		lap-=secs*1000;
		if (secs!="00") unt++;

		// make sure millisecs is 3 digits
		milli=lap.toString();
		while (milli.length<3) {milli="0"+milli}
		// add string of units
		switch (unt) {
			case 0: str=milli+" millisecs"; break;
			case 1:
				if (option=="milli") str=secs+"."+milli+" secs";
				else str=secs+" secs";
				break;
			case 2:
				if (option=="milli") str=mins+":"+secs+"."+milli+" mins";
				else str=mins+":"+secs+" mins";
				break;
			case 3:
				if (option=="milli") str=hrs+"hrs "+mins+":"+secs+"."+milli+" mins";
				else str=hrs+"hrs "+mins+":"+secs+"mins";
				break;
			case 4:
				if (option=="milli") str=days+" days "+hrs+":"+mins+" hrs "+secs+"."+milli+" secs";
				else str=days+" days "+hrs+":"+mins+"hrs "+secs+'.'+milli+'secs';
				break;
		}
		//app.SetDebugEnabled(true); // re-enable debug
		return str;
	} // Time (option)
	//app.SetDebugEnabled(true); // re-enable debug
} // sWatch()
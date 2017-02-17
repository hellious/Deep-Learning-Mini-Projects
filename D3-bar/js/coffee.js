var chart;
var height = 200;
var width = 300;
//DEFINE YOUR VARIABLES UP HERE
var margin = {top : 10, right : 20, bottom : 30, left : 10 };
var vg_height = height - margin.top-margin.bottom;
var vg_width = width - margin.right-margin.left;
var x_scale,y_scale,X,Y;

// for getting domain of x
function getXValue(data,X_S){
    var obj = [];
    for(var index in data){
        obj.push(data[index][X_S]);
    }
    return obj;
}
// for filling the color in bar
function getColor(i){
    var color = ["SteelBlue","DarkOrange","LimeGreen","Crimson"];
    return color[i];
}
// getting the data in the form of key value pair
function getData(map_xy,X_S,Y_S){
    var data = new Array();
    for( var key in map_xy){
        var elem = {};
        elem[X_S] = key;
        elem[Y_S] = map_xy[key];
        data.push(elem);    
    }
    return data;
}
//get max value for given 
function getMax(map_temp,len){
    var max = -Infinity;
    for(var i=0;i<len;i++){
        var val = map_temp[Object.keys(map_temp)[i]];
        if (val > max){
           // alert(max);
            max = val;
        }
    }
    return max;
}
//Gets called when the page is loaded.
function init(){
  chart = d3.select('#vis').append('svg');
  vis = chart.append('g');
  //PUT YOUR INIT CODE BELOW
  chart = chart.attr("width", 450)
                .attr("height", 200)
                .attr("viewBox", "0 0 " +( width+30)+ " " + height)
  x_scale = d3.scaleBand().rangeRound([0, vg_width]);
  y_scale = d3.scaleLinear().range([vg_height, 0]);
  X = d3.axisBottom().scale(x_scale);
  Y = d3.axisRight().scale(y_scale).ticks(5);
  

}

//Called when the update button is clicked
function updateClicked(){
    d3.csv('data/CoffeeData.csv',update);
  
}

//Callback for when data is loaded
function update(rawdata){
    
  //PUT YOUR UPDATE CODE BELOW
    // map for storing the summation of y value for a given x axis value
    var map_xy = {};
    var X_S = getXSelectedOption();
    var Y_S = getYSelectedOption();
    
    // parsing the raw data
    rawdata.forEach(function(row){
        if(map_xy[row[X_S]]==undefined){
            map_xy[row[X_S]] = parseInt(row[Y_S]);
        }else{
            map_xy[row[X_S]] = parseInt(map_xy[row[X_S]]) + parseInt(row[Y_S]);
        }
    });
    
    // setting the domain of x and y value for plotting the bars
    var len_arr = Object.keys(map_xy).length;
    var domain_y = getMax(map_xy,len_arr);
    var data = getData(map_xy,X_S,Y_S);
    var domain_x = getXValue(data,X_S);
    
    // setting the domain
    y_scale.domain([0,domain_y]);
    x_scale.domain(domain_x);
    
    // removing the content before adding new data
    d3.selectAll("svg").selectAll("*").remove();
    
    
    // append new add after updating
    chart.append("g")
        .selectAll(".bar")
        .data(data)
        .enter()
        .append("rect")
        .attr("class","bar")
        .attr("x",function(elem){ return x_scale(elem[X_S]); })
        .attr("width",function(elem){ return x_scale.bandwidth()-3; })
        .attr("y",function(elem){ return y_scale(elem[Y_S]); })
        .attr("height",function(elem){ return vg_height - y_scale(elem[Y_S]); })
        .attr("fill",function(elem,i){return getColor(i);});
    
    //appending the x axis to the chart
    chart.append("g").attr("class", "x axis")
                    .attr("transform", "translate(0," + (vg_height) + ")")
                    .call(X)
                    .selectAll("text")
                    .style("text-anchor", "middle")
                    .style("font-size",13)
                    .style("font-family","TimesNewRoman");
    
    //appending y axis to the chart
    chart.append("g").attr("class", "y axis")
                    .attr("transform", "translate(" + (vg_width) + ",0)")
                    .call(Y)
                    .selectAll("text") 
                    .style("text-anchor", "start")    
                    .style("font-size",13)
                    .style("font-family","TimesNewRoman");
                                                               
       


}

// Returns the selected option in the X-axis dropdown. Use d[getXSelectedOption()] to retrieve value instead of d.getXSelectedOption()
function getXSelectedOption(){
  var node = d3.select('#xdropdown').node();
  var i = node.selectedIndex;
  return node[i].value;
}

// Returns the selected option in the X-axis dropdown. 
function getYSelectedOption(){
  var node = d3.select('#ydropdown').node();
  var i = node.selectedIndex;
  return node[i].value;
}


// References : https://github.com/d3/d3/wiki
//References: https://bl.ocks.org/d3noob/bdf28027e0ce70bd132edc64f1dd7ea4

// DATA TO LOAD
var students;
var studentNames;

function initGrid() {
    students = new Array();
    studentNames = new Array();
    var dataFile = "./js/OfficeHoursGridData.json";
    loadData(dataFile);
}

function loadData(jsonFile) {
    $.getJSON(jsonFile, function (json) {
	initPage(json);
    });
}

function initPage(data) {
    // FIRST ADD THE TEAM TABLES
    for (var i = 0; i < data.officeHours.length; i++) {
	var id = data.officeHours[i].day + "_" + data.officeHours[i].time;
	var name = data.officeHours[i].name;
	var cell = $("#" + id);
	if (name === "Lecture") {
	    cell.removeClass("open");
	    cell.addClass("lecture");
	    cell.html("Lecture");
	}
	else {
	    cell.removeClass("open");
	    cell.addClass("time");
	    cell.append(name);
	}
    }
}
game.log("Game Initialization");

Object.addEventListener("game.tick", function (ev) {
	game.log("tick.", ev.deltaTime);
});

true;
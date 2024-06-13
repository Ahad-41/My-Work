let boxes = document.querySelectorAll(".box");
let resetBtn = document.querySelector("#reset-btn");
let newGameBtn = document.querySelector("#new-btn");
let msgContainer = document.querySelector(".msg-container");
let msg = document.querySelector("#msg");

let turnX = true;
const winPatterns = [
    [0, 1, 2],
    [3, 4, 5],
    [6, 7, 8],
    [0, 3, 6],
    [1, 4, 7],
    [2, 5, 8],
    [0, 4, 8],
    [2, 4, 6],
];

const resetGame = () => {
    msgContainer.classList.add("hide");
    turnX = true;
    for (let box of boxes) {
        box.disabled = false;
        box.innerText = "";
        box.style.backgroundColor = "#ffffc7"
    }
}
resetBtn.addEventListener("click", resetGame);
newGameBtn.addEventListener("click", resetGame);

boxes.forEach((box) => {
    box.addEventListener("click", () => {
        if (turnX) {
            box.innerText = "X";
            box.style.backgroundColor = "Green";
        }
        else {
            box.innerText = "O";
            box.style.backgroundColor = "Red";
        }
        box.style.color = "White";
        box.disabled = true;
        turnX = !turnX;

        checkWinner();
        checkDraw();
    });
});

const checkDraw = () => {
    let cnt = 0;
    for (let box of boxes) {
        if (box.innerText != "") cnt++;
    }
    if (cnt === 9) {
        msg.innerText = "Match is Draw";
        msgContainer.classList.remove("hide");
    }
}

const checkWinner = () => {
    for (let pattern of winPatterns) {
        let pos1Val = boxes[pattern[0]].innerText;
        let pos2Val = boxes[pattern[1]].innerText;
        let pos3Val = boxes[pattern[2]].innerText;

        if (pos1Val != "" && pos2Val != "" && pos3Val != "") {
            if (pos1Val === pos2Val && pos2Val === pos3Val) showWinner(pos1Val);
        }
    }
}

const showWinner = (winner) => {
    msg.innerText = `Congratulations, Winner is ${(winner === 'X'? "First" : "Second")} Player`;
    msgContainer.classList.remove("hide"); 
    for (let box of boxes) box.disabled = true;
}
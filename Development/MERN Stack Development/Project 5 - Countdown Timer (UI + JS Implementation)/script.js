const startDate = new Date().getTime();
// var endDate = new Date("13 May, 2026 13:50:00").getTime();

const timerInput = document.getElementById("timerInput");
const setButton = document.getElementById("setButton");

function setTimer(timerInput)
{
    if (timerInput.trim() === "")
    {
        alert("Input should not be empty!");
        return;
    }

    const newEndDate = new Date(timerInput).getTime();

    if (isNaN(newEndDate))
    {
        alert("Invalid date format! Please enter a valid date.");
        return;
    }

    if (newEndDate <= new Date().getTime())
    {
        alert("Please enter a future date and time.");
        return;
    }

    endDate = newEndDate;
}

setButton.addEventListener("click", function()
{
    const timerValue = timerInput.value;
    setTimer(timerValue);
});

let x = setInterval(function updateTimer()
{

    const now = new Date().getTime();

    const elapsedTime = now - startDate;
    const remainingTime = endDate - now;
    const totalTime = endDate - startDate;

    const dayInMS = 24*60*60*1000;
    const hoursInMS = 60*60*1000;
    const minutesInMS = 60*1000;

    const days = Math.floor(remainingTime/dayInMS);
    const hrs = Math.floor((remainingTime%dayInMS)/hoursInMS);
    const mins = Math.floor((remainingTime%hoursInMS)/minutesInMS);
    const secs = Math.floor((remainingTime%minutesInMS)/1000);

    const progressPercentage = (elapsedTime/totalTime)*100;

    const daysLabel = document.getElementById("days");
    const hoursLabel = document.getElementById("hours");
    const minutesLabel = document.getElementById("minutes");
    const secondsLabel = document.getElementById("seconds");

    daysLabel.textContent = days;
    hoursLabel.textContent = hrs;
    minutesLabel.textContent = mins;
    secondsLabel.textContent = secs;

    const progress = document.getElementById("progressCompleted");

    progress.style.width = progressPercentage + "%";

    const expiredText = document.getElementById("fragmentContainer");

    const one = 1;

    if (remainingTime < 0)
    {
        clearInterval(x);
        expiredText.innerHTML = '<h1>TIMER EXPIRED!</h1>';
        progress.style.width = "100%";
    }

}, 1000);
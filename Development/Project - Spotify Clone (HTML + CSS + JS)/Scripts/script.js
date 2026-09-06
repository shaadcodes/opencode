let currentAudio = new Audio();
let currentThumb = new Image();
let currentTrack;
let imageTrack;
let currentPlaylistName;
let currentCard;
let currentCardStack;

document.addEventListener("DOMContentLoaded", async function () {
  let playlistLinks = await loadPlaylists();
  let playlistsContainer = document.querySelector(".playlistsContainer");
  let audioWindow = document.querySelector(".musicWindow");
  let currentImage = document.getElementById("currentImage");
  let currentTitle = document.getElementById("currentTitle");
  playlistLinks.forEach((link) => {
    let playlistName = link
      .split("Music/")[1]
      .replaceAll("%20", " ")
      .split("/")[0];

    playlistsContainer.innerHTML =
      playlistsContainer.innerHTML +
      `<div class="playlistCard hover">
            <img
            src=${link}/100.jpg
            alt="Playlist"
            />
            <div class="svgContainer hover">
                <svg
                    data-encore-id="icon"
                    role="img"
                    aria-hidden="true"
                    class="e-10451-icon"
                    viewBox="0 0 24 24"
                    style="
                    --encore-icon-height: var(
                        --encore-graphic-size-decorative-base
                    );
                    --encore-icon-width: var(
                        --encore-graphic-size-decorative-base
                    );
                    "
                    >
                <path
                    d="m7.05 3.606 13.49 7.788a.7.7 0 0 1 0 1.212L7.05 20.394A.7.7 0 0 1 6 19.788V4.212a.7.7 0 0 1 1.05-.606"
                ></path>
                </svg>
            </div>
            <div class="pCardText">
                <h3>${playlistName}</h3>
            </div>
        </div>`;
  });

  let playlistCards = Array.from(document.querySelectorAll(".playlistCard"));
  let linkIndex = 0;

  playlistCards.forEach((card) => {
    let link = playlistLinks[linkIndex];
    card.addEventListener("click", async () => {
      currentTrack = await loadAudioFiles(link.split("Music/")[1]);
      let imageFiles = (await loadImageFiles(link.split("Music/")[1])).slice(1);
      imageTrack = imageFiles;
      currentPlaylistName = link;
      let imageIndex = 0;
      audioWindow.innerHTML = "";
      currentTrack.forEach((audioFile) => {
        let audioName = audioFile
          .split(`${link}`)[1]
          .replaceAll("%20", " ")
          .split(".mp3")[0];
        audioWindow.innerHTML =
          audioWindow.innerHTML +
          `<div class="musicCard">
            <div class="leftCard">
                <div class="imgContainer">
                    <img
                    src=${imageFiles[imageIndex]}
                    alt=
                    />
                </div>
                <div class="titleContainer">
                    <p>${audioName}</p>
                </div>
            </div>
            <div class="svgContainer hover">
                <svg
                    data-encore-id="icon"
                    role="img"
                    aria-hidden="true"
                    class="e-10451-icon"
                    viewBox="0 0 24 24"
                    style="
                    --encore-icon-height: var(
                        --encore-graphic-size-decorative-base
                    );
                    --encore-icon-width: var(
                        --encore-graphic-size-decorative-base
                    );
                    "
                >
                <path
                    d="m7.05 3.606 13.49 7.788a.7.7 0 0 1 0 1.212L7.05 20.394A.7.7 0 0 1 6 19.788V4.212a.7.7 0 0 1 1.05-.606"
                ></path>
                </svg>
            </div>
        </div>`;
        imageIndex++;
      });
      let audioCards = document.querySelectorAll(".musicCard");
      currentCardStack = audioCards;
      for (let cardIndex = 0; cardIndex < audioCards.length; cardIndex++) {
        const card = audioCards[cardIndex];
        card.addEventListener("click", () => {
          currentAudio.src = currentTrack[cardIndex];
          currentImage.src = imageFiles[cardIndex];
          currentTitle.innerHTML = card.getElementsByTagName("p")[0].innerHTML;
          currentCard = card;
          let currentContainer = card.querySelector(".svgContainer");
          card.addEventListener("click", () => {
            if (currentAudio.paused) {
              currentAudio.play();
              volumeProgress.style.width = 100 + `%`;
              currentContainer.innerHTML = `<svg data-encore-id="icon" role="img" aria-hidden="true" class="e-10451-icon" viewBox="0 0 16 16" style="--encore-icon-height: var(--encore-graphic-size-decorative-smaller); --encore-icon-width: var(--encore-graphic-size-decorative-smaller);"><path d="M2.7 1a.7.7 0 0 0-.7.7v12.6a.7.7 0 0 0 .7.7h2.6a.7.7 0 0 0 .7-.7V1.7a.7.7 0 0 0-.7-.7zm8 0a.7.7 0 0 0-.7.7v12.6a.7.7 0 0 0 .7.7h2.6a.7.7 0 0 0 .7-.7V1.7a.7.7 0 0 0-.7-.7z"></path></svg>`;
              for (let i = 0; i < audioCards.length; i++) {
                const cards = audioCards[i];
                if (i == cardIndex) {
                  continue;
                } else {
                  cards.querySelector(".svgContainer").innerHTML =
                    `<svg data-encore-id="icon" role="img" aria-hidden="true" class="e-10451-icon" viewBox="0 0 24 24" style="--encore-icon-height: var(--encore-graphic-size-decorative-base); --encore-icon-width: var(--encore-graphic-size-decorative-base);"><path d="m7.05 3.606 13.49 7.788a.7.7 0 0 1 0 1.212L7.05 20.394A.7.7 0 0 1 6 19.788V4.212a.7.7 0 0 1 1.05-.606"></path></svg>`;
                }
              }
            } else {
              currentAudio.pause();
              card.querySelector(".svgContainer").innerHTML =
                `<svg data-encore-id="icon" role="img" aria-hidden="true" class="e-10451-icon" viewBox="0 0 24 24" style="--encore-icon-height: var(--encore-graphic-size-decorative-base); --encore-icon-width: var(--encore-graphic-size-decorative-base);"><path d="m7.05 3.606 13.49 7.788a.7.7 0 0 1 0 1.212L7.05 20.394A.7.7 0 0 1 6 19.788V4.212a.7.7 0 0 1 1.05-.606"></path></svg>`;
            }
          });
        });
      }
    });
    linkIndex++;
  });
  let previousButton = document.getElementById("previous");
  let playButton = document.querySelector(".playWrapper");
  let nextButton = document.getElementById("next");
  let timeElapsed = document.getElementById("elapsed");
  let timeTotal = document.getElementById("total");
  let progressWrapper = document.querySelector(".progressWrapper");
  let progress = document.querySelector(".progressFilled");
  let volumeButton = document.getElementById("volume");
  let volumeWrapper = document.querySelector(".volumeWrapper");
  let volumeProgress = document.querySelector(".volumeFilled");

  currentAudio.addEventListener("timeupdate", () => {
    if (currentAudio.paused) {
      playButton.innerHTML = `<svg data-encore-id="icon" role="img" aria-hidden="true" class="e-10451-icon" viewBox="0 0 24 24" style="--encore-icon-height: var(--encore-graphic-size-decorative-base); --encore-icon-width: var(--encore-graphic-size-decorative-base);"><path d="m7.05 3.606 13.49 7.788a.7.7 0 0 1 0 1.212L7.05 20.394A.7.7 0 0 1 6 19.788V4.212a.7.7 0 0 1 1.05-.606"></path></svg>`;

      currentCard.querySelector(".svgContainer").innerHTML =
        `<svg data-encore-id="icon" role="img" aria-hidden="true" class="e-10451-icon" viewBox="0 0 24 24" style="--encore-icon-height: var(--encore-graphic-size-decorative-base); --encore-icon-width: var(--encore-graphic-size-decorative-base);"><path d="m7.05 3.606 13.49 7.788a.7.7 0 0 1 0 1.212L7.05 20.394A.7.7 0 0 1 6 19.788V4.212a.7.7 0 0 1 1.05-.606"></path></svg>`;
    } else {
      playButton.innerHTML = `<svg data-encore-id="icon" role="img" aria-hidden="true" class="e-10451-icon" viewBox="0 0 16 16" style="--encore-icon-height: var(--encore-graphic-size-decorative-smaller); --encore-icon-width: var(--encore-graphic-size-decorative-smaller);"><path d="M2.7 1a.7.7 0 0 0-.7.7v12.6a.7.7 0 0 0 .7.7h2.6a.7.7 0 0 0 .7-.7V1.7a.7.7 0 0 0-.7-.7zm8 0a.7.7 0 0 0-.7.7v12.6a.7.7 0 0 0 .7.7h2.6a.7.7 0 0 0 .7-.7V1.7a.7.7 0 0 0-.7-.7z"></path></svg>`;

      currentCard.querySelector(".svgContainer").innerHTML =
        `<svg data-encore-id="icon" role="img" aria-hidden="true" class="e-10451-icon" viewBox="0 0 16 16" style="--encore-icon-height: var(--encore-graphic-size-decorative-smaller); --encore-icon-width: var(--encore-graphic-size-decorative-smaller);"><path d="M2.7 1a.7.7 0 0 0-.7.7v12.6a.7.7 0 0 0 .7.7h2.6a.7.7 0 0 0 .7-.7V1.7a.7.7 0 0 0-.7-.7zm8 0a.7.7 0 0 0-.7.7v12.6a.7.7 0 0 0 .7.7h2.6a.7.7 0 0 0 .7-.7V1.7a.7.7 0 0 0-.7-.7z"></path></svg>`;
    }
    timeTotal.innerHTML = secondsToMinutesSeconds(currentAudio.duration);
    timeElapsed.innerHTML = secondsToMinutesSeconds(currentAudio.currentTime);
    let progressPercentage =
      (currentAudio.currentTime / currentAudio.duration) * 100;
    progress.style.width = progressPercentage + `%`;
  });

  playButton.addEventListener("click", () => {
    if (currentAudio.paused) {
      currentAudio.play();
    } else {
      currentAudio.pause();
    }
  });

  progressWrapper.addEventListener("click", (wrapper) => {
    progressPercentage =
      (wrapper.offsetX / wrapper.currentTarget.getBoundingClientRect().width) *
      100;
    progress.style.width = Math.floor(progressPercentage) + `%`;
    currentAudio.currentTime =
      (progressPercentage / 100) * currentAudio.duration;
  });

  previousButton.addEventListener("click", () => {
    let indexOfCurrentAudio = currentTrack.indexOf(currentAudio.src);
    let cardIndex = Array.from(currentCardStack).indexOf(currentCard);
    if (indexOfCurrentAudio > 0) {
      currentAudio.src = currentTrack[indexOfCurrentAudio - 1];
      currentImage.src = imageTrack[indexOfCurrentAudio - 1];
      currentTitle.innerHTML = currentTrack[indexOfCurrentAudio - 1]
        .split(`${currentPlaylistName}`)[1]
        .replaceAll("%20", " ")
        .split(".mp3")[0];
      currentCard = currentCardStack[cardIndex - 1];
      cardIndex--;
      currentAudio.play();
      for (let i = 0; i < currentCardStack.length; i++) {
        const card = currentCardStack[i];
        if (i == cardIndex) {
          currentCard.querySelector(".svgContainer").innerHTML =
            `<svg data-encore-id="icon" role="img" aria-hidden="true" class="e-10451-icon" viewBox="0 0 16 16" style="--encore-icon-height: var(--encore-graphic-size-decorative-smaller); --encore-icon-width: var(--encore-graphic-size-decorative-smaller);"><path d="M2.7 1a.7.7 0 0 0-.7.7v12.6a.7.7 0 0 0 .7.7h2.6a.7.7 0 0 0 .7-.7V1.7a.7.7 0 0 0-.7-.7zm8 0a.7.7 0 0 0-.7.7v12.6a.7.7 0 0 0 .7.7h2.6a.7.7 0 0 0 .7-.7V1.7a.7.7 0 0 0-.7-.7z"></path></svg>`;
        } else {
          card.querySelector(".svgContainer").innerHTML =
            `<svg data-encore-id="icon" role="img" aria-hidden="true" class="e-10451-icon" viewBox="0 0 24 24" style="--encore-icon-height: var(--encore-graphic-size-decorative-base); --encore-icon-width: var(--encore-graphic-size-decorative-base);"><path d="m7.05 3.606 13.49 7.788a.7.7 0 0 1 0 1.212L7.05 20.394A.7.7 0 0 1 6 19.788V4.212a.7.7 0 0 1 1.05-.606"></path></svg>`;
        }
      }
    }
  });

  nextButton.addEventListener("click", () => {
    let indexOfCurrentAudio = currentTrack.indexOf(currentAudio.src);
    let cardIndex = Array.from(currentCardStack).indexOf(currentCard);
    if (indexOfCurrentAudio < currentTrack.length - 1) {
      currentAudio.src = currentTrack[indexOfCurrentAudio + 1];
      currentImage.src = imageTrack[indexOfCurrentAudio + 1];
      currentTitle.innerHTML = currentTrack[indexOfCurrentAudio + 1]
        .split(`${currentPlaylistName}`)[1]
        .replaceAll("%20", " ")
        .split(".mp3")[0];
      currentCard = currentCardStack[cardIndex + 1];
      cardIndex++;
      currentAudio.play();
      for (let i = 0; i < currentCardStack.length; i++) {
        const card = currentCardStack[i];
        if (i == cardIndex) {
          currentCard.querySelector(".svgContainer").innerHTML =
            `<svg data-encore-id="icon" role="img" aria-hidden="true" class="e-10451-icon" viewBox="0 0 16 16" style="--encore-icon-height: var(--encore-graphic-size-decorative-smaller); --encore-icon-width: var(--encore-graphic-size-decorative-smaller);"><path d="M2.7 1a.7.7 0 0 0-.7.7v12.6a.7.7 0 0 0 .7.7h2.6a.7.7 0 0 0 .7-.7V1.7a.7.7 0 0 0-.7-.7zm8 0a.7.7 0 0 0-.7.7v12.6a.7.7 0 0 0 .7.7h2.6a.7.7 0 0 0 .7-.7V1.7a.7.7 0 0 0-.7-.7z"></path></svg>`;
        } else {
          card.querySelector(".svgContainer").innerHTML =
            `<svg data-encore-id="icon" role="img" aria-hidden="true" class="e-10451-icon" viewBox="0 0 24 24" style="--encore-icon-height: var(--encore-graphic-size-decorative-base); --encore-icon-width: var(--encore-graphic-size-decorative-base);"><path d="m7.05 3.606 13.49 7.788a.7.7 0 0 1 0 1.212L7.05 20.394A.7.7 0 0 1 6 19.788V4.212a.7.7 0 0 1 1.05-.606"></path></svg>`;
        }
      }
    }
  });

  volumeButton.addEventListener("click", () => {
    let mute = document.getElementById("mute");
    if (currentAudio.muted) {
      currentAudio.muted = false;
      mute.style = `position: absolute;
                  height: 0.1rem;
                  width: 0rem;
                  background-color: var(--unfocused);
                  rotate: -45deg;
                  translate: -0.1rem 1rem;
                  transition: all 0.3s ease-out;`;
    } else {
      mute.style = `position: absolute;
                  height: 0.1rem;
                  width: 1.3rem;
                  background-color: var(--unfocused);
                  rotate: -45deg;
                  translate: -0.1rem 0.5rem;
                  transition: all 0.3s ease-in;`;
      currentAudio.muted = true;
    }
  });

  volumeWrapper.addEventListener("click", (wrapper) => {
    let volumePercentage =
      (wrapper.offsetX / wrapper.currentTarget.getBoundingClientRect().width) *
      100;
    volumeProgress.style.width = volumePercentage + `%`;
    currentAudio.volume = (volumePercentage / 100) * 1;
  });
});

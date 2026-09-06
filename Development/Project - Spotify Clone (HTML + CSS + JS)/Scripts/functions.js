function secondsToMinutesSeconds(seconds) {
  let minutes = Math.floor(seconds / 60);
  seconds = Math.floor(seconds - minutes * 60);
  if (seconds < 10) seconds = 0 + `${seconds}`;
  return `${minutes}:${seconds}`;
}

async function loadPlaylists() {
  let fetchLists = await fetch(
    "http://127.0.0.1:3000/Development/Project%20-%20Spotify%20Clone%20(HTML%20+%20CSS%20+%20JS)/Assets/Music/",
  );
  let response = await fetchLists.text();
  let dummyDiv = document.createElement("div");
  dummyDiv.innerHTML = response;
  let playlistArray = Array.from(dummyDiv.getElementsByTagName("a")).slice(
    1,
    length - 1,
  );
  let playlistLinks = [];
  playlistArray.forEach((listLink) => {
    playlistLinks.push(listLink.href);
  });
  return playlistLinks;
}

async function loadAudioFiles(playlist) {
  let fetchAudios = await fetch(
    `http://127.0.0.1:3000/Development/Project%20-%20Spotify%20Clone%20(HTML%20+%20CSS%20+%20JS)/Assets/Music/${playlist}`,
  );

  let response = await fetchAudios.text();
  let dummyDiv = document.createElement("div");
  dummyDiv.innerHTML = response;
  let audioLinks = [];

  Array.from(dummyDiv.getElementsByTagName("a")).forEach((link) => {
    if (link.href.endsWith(".mp3")) {
      audioLinks.push(link.href);
    }
  });

  return audioLinks;
}

async function loadImageFiles(playlist) {
  let fetchAudios = await fetch(
    `http://127.0.0.1:3000/Development/Project%20-%20Spotify%20Clone%20(HTML%20+%20CSS%20+%20JS)/Assets/Music/${playlist}`,
  );

  let response = await fetchAudios.text();
  let dummyDiv = document.createElement("div");
  dummyDiv.innerHTML = response;
  let imageLinks = [];

  Array.from(dummyDiv.getElementsByTagName("a")).forEach((link) => {
    if (link.href.endsWith(".jpg")) {
      imageLinks.push(link.href);
    }
  });

  return imageLinks;
}

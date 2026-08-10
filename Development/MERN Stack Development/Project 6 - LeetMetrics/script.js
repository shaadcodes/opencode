document.addEventListener("DOMContentLoaded", function () {
  const searchbtn = document.getElementById("searchbutton");
  const userNameInput = document.getElementById("username");
  const easyCircle = document.getElementById("easy");
  const easyText = document.getElementById("easytext");
  const mediumCircle = document.getElementById("medium");
  const mediumText = document.getElementById("mediumtext");
  const hardCircle = document.getElementById("hard");
  const hardText = document.getElementById("hardtext");

  function validateUserName(username) {
    if (username.trim() === "") {
      alert("Username cannot be empty!");
      return false;
    }

    const regex = /^[a-zA-Z][a-zA-Z0-9_]{2,15}$/;
    if (regex.test(username)) {
      return true;
    } else {
      alert("Invalid Username!");
      return false;
    }
  }

  // GraphQL query to get total questions & user solved counts in one request
  const fetchLeetCodeProfileGraphQL = async (username) => {
    const query = `
      query getUserStats($username: String!) {
        allQuestionsCount {
          difficulty
          count
        }
        matchedUser(username: $username) {
          submitStatsGlobal {
            acSubmissionNum {
              difficulty
              count
            }
          }
        }
      }
    `;

    try {
      const response = await fetch("https://corsproxy.io/?https://leetcode.com/graphql/", {
        method: "POST",
        headers: {
          "Content-Type": "application/json",
        },
        body: JSON.stringify({
          query,
          variables: { username },
        }),
      });

      if (!response.ok) {
        throw new Error("GraphQL request failed");
      }

      const result = await response.json();

      if (result.errors || !result.data.matchedUser) {
        throw new Error("User not found!");
      }

      // Extract total questions
      const totals = result.data.allQuestionsCount;
      const totalEasy = totals.find((q) => q.difficulty === "Easy")?.count || 1;
      const totalMedium = totals.find((q) => q.difficulty === "Medium")?.count || 1;
      const totalHard = totals.find((q) => q.difficulty === "Hard")?.count || 1;

      // Extract user solved questions
      const solved = result.data.matchedUser.submitStatsGlobal.acSubmissionNum;
      const easySolved = solved.find((s) => s.difficulty === "Easy")?.count || 0;
      const mediumSolved = solved.find((s) => s.difficulty === "Medium")?.count || 0;
      const hardSolved = solved.find((s) => s.difficulty === "Hard")?.count || 0;

      return {
        easyQs: totalEasy,
        easySolved,
        mediumQs: totalMedium,
        mediumSolved,
        hardQs: totalHard,
        hardSolved,
      };
    } catch (error) {
      console.error("Error fetching LeetCode profile:", error);
      throw error;
    }
  };

  searchbtn.addEventListener("click", async function () {
    const username = userNameInput.value;

    if (validateUserName(username)) {
      console.log("Fetching profile for: " + username);
      try {
        const stats = await fetchLeetCodeProfileGraphQL(username);

        // Update Text
        easyText.textContent = `${stats.easySolved} / ${stats.easyQs}`;
        mediumText.textContent = `${stats.mediumSolved} / ${stats.mediumQs}`;
        hardText.textContent = `${stats.hardSolved} / ${stats.hardQs}`;

        // Calculate Percentages
        const easyPercentage = (stats.easySolved / stats.easyQs) * 100;
        const mediumPercentage = (stats.mediumSolved / stats.mediumQs) * 100;
        const hardPercentage = (stats.hardSolved / stats.hardQs) * 100;

        // Trigger animations
        setPercentage(easyCircle, easyPercentage);
        setPercentage(mediumCircle, mediumPercentage);
        setPercentage(hardCircle, hardPercentage);

      } catch (error) {
        alert(error.message);
      }
    }
  });

  function setPercentage(element, percentValue) {
    // Reset to 0% first
    element.style.setProperty("--percentvalue", "0%");

    // Wait 2 frames so the browser renders 0% before transitioning
    requestAnimationFrame(() => {
      requestAnimationFrame(() => {
        element.style.setProperty("--percentvalue", `${percentValue}%`);
      });
    });
  }
});
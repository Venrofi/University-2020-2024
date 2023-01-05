const input = document.querySelector("#newTaskInput");
const addTaskButton = document.querySelector("#addTask");
const datalist = document.querySelector("datalist");
const toDoListWrapper = document.querySelector(".listOfTasks");
const doneListWrapper = document.querySelector(".listOfDoneTasks");
const toDoList = document.querySelector(".todo-list");
const doneList = document.querySelector(".done-list");

let options = [];
let todoTasks = [];
let doneTasks = [];
window.addEventListener("load", () => {
  getSuggestions();
  getTasks();
  getDoneTasks();
});

input.addEventListener("input", (e) => {
  // Clear the options
  while (datalist.firstChild) {
    datalist.removeChild(datalist.firstChild);
  }

  // Add new options based on the input value
  for (const option of options) {
    const lowerCaseOption = option.toLowerCase();
    const inputLowerCase = e.target.value.toLowerCase();

    if (lowerCaseOption.includes(inputLowerCase)) {
      const optionElement = document.createElement("option");
      optionElement.value = option;
      datalist.appendChild(optionElement);
    }
  }
});

addTaskButton.addEventListener("click", () => {
  if (input.value !== "") {
    const toDoItem = document.createElement("li");

    toDoItem.innerHTML = input.value;
    toDoItem.classList.add("list-item");

    const buttonsContainer = createButtons(toDoItem);
    toDoItem.appendChild(buttonsContainer);
    toDoList.appendChild(toDoItem);

    addNewOption(input.value);
    todoTasks.push(input.value);

    console.log("New task added!");
    console.log("Todo:", todoTasks, "Done:", doneTasks);

    input.value = "";
  }

  if (toDoList.querySelector("li")) {
    toDoListWrapper.style.display = "block";
  }
});

function getSuggestions() {
  const xhr = new XMLHttpRequest();
  xhr.onreadystatechange = () => {
    if (xhr.readyState !== 4) return;

    if (xhr.status === 200 || xhr.status === 304) {
      try {
        const xmlData = xhr.responseXML;
        const data = xmlData.childNodes[0].childNodes;
        // console.log("CUSTOM", data[5]);

        //Loop through each group of suggestions
        for (let i = 1; i < data.length; i += 2) {
          const group = data[i].childNodes;

          //Loop through each element from the group
          for (let j = 1; j < group.length; j += 2) {
            options.push(group[j].textContent);
          }
        }
        console.log(options, options.length);
      } catch (error) {
        console.error(error);
      }
    }
  };
  xhr.open("GET", "./php/getSuggestions.php", true);
  xhr.setRequestHeader("Content-Type", " application/xml");
  xhr.send();
}

function getTasks() {}

function getDoneTasks() {}

function updateTasks() {}

function updateDoneTasks() {}

function addNewOption(option) {
  if (!options.includes(option)) {
    options.push(option);

    const xhr = new XMLHttpRequest();
    xhr.onreadystatechange = () => {
      if (xhr.readyState !== 4) return;

      if (xhr.status === 200 || xhr.status === 304) {
        try {
          console.log("New option saved!", xhr.responseText, Date());
        } catch (error) {
          console.error(error);
        }
      }
    };

    xhr.open("POST", "./php/addNewSuggestion.php", true);
    xhr.setRequestHeader("Content-Type", "text/plain");
    xhr.send(option);
  }
}

function moveTaskToDone(item) {
  const buttonsContainer = item.querySelector("div");
  const restoreButton = document.createElement("button");

  restoreButton.innerHTML = "↩";
  restoreButton.addEventListener("click", () => {
    restoreTaskFromDone(item);
  });

  item.removeChild(buttonsContainer);
  item.appendChild(restoreButton);
  doneList.appendChild(item);

  todoTasks = todoTasks.filter((task) => task !== item.firstChild.data);
  doneTasks.push(item.firstChild.data);

  console.log("Task moved to done!");
  console.log("Todo:", todoTasks, "Done:", doneTasks);

  if (doneList.querySelector("li")) {
    doneListWrapper.style.display = "block";
  }
}

function restoreTaskFromDone(item) {
  const restoreButton = item.querySelector("button");
  const buttonsContainer = createButtons(item);

  item.removeChild(restoreButton);
  item.appendChild(buttonsContainer);

  toDoList.appendChild(item);
  todoTasks.push(item.firstChild.data);
  doneTasks = doneTasks.filter((task) => task !== item.firstChild.data);

  console.log("Task restored!");
  console.log("Todo:", todoTasks, "Done:", doneTasks);

  if (toDoList.querySelector("li")) {
    toDoListWrapper.style.display = "block";
  }
  if (!doneList.querySelector("li")) {
    doneListWrapper.style.display = "none";
  }
}

function createButtons(item) {
  const buttonsContainer = document.createElement("div");
  const completeButton = document.createElement("button");
  const deleteButton = document.createElement("button");

  deleteButton.innerHTML = "❌";
  completeButton.innerHTML = "✅";

  deleteButton.addEventListener("click", () => {
    item.remove();

    todoTasks = todoTasks.filter((task) => task !== item.firstChild.data);
    console.log("Task deleted!");
    console.log("Todo:", todoTasks, "Done:", doneTasks);

    if (!toDoList.querySelector("li")) {
      toDoListWrapper.style.display = "none";
    }
  });
  completeButton.addEventListener("click", () => {
    moveTaskToDone(item);
    if (!toDoList.querySelector("li")) {
      toDoListWrapper.style.display = "none";
    }
  });

  buttonsContainer.style = "display: flex; gap: .5rem";
  buttonsContainer.appendChild(completeButton);
  buttonsContainer.appendChild(deleteButton);

  return buttonsContainer;
}

// PHP ma 3 zbiory: lista podpowiedzi, lista to-do, lista done
// Sprawdzać czy input jest czymś nowym, jeśli tak to dodać go do listy podpowiedzi

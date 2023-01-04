const input = document.querySelector("#newTaskInput");
const addTaskButton = document.querySelector("#addTask");
const datalist = document.querySelector("datalist");
const toDoListWrapper = document.querySelector(".listOfTasks");
const doneListWrapper = document.querySelector(".listOfDoneTasks");
const toDoList = document.querySelector(".todo-list");
const doneList = document.querySelector(".done-list");

let options = [];
fetch("./php/data/suggestions.json")
  .then((res) => res.json())
  .then((data) => {
    let movies = data.data.movies.map((movie) => "obejrzeć: " + movie);
    let books = data.data.books.map((book) => "przeczytać: " + book);
    let programmingBooks = data.data.programmingBooks.map(
      (book) => "przeczytać: " + book
    );

    options = [
      ...data.data.custom,
      ...data.data.beers,
      ...data.data.fruits,
      ...data.data.vegetables,
      ...books,
      ...movies,
      ...programmingBooks,
    ];
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
    input.value = "";
  }

  if (toDoList.querySelector("li")) {
    toDoListWrapper.style.display = "block";
  }
});

function addNewOption(option) {
  if (!options.includes(option)) {
    options.push(option);
    console.log("New option added!", option);
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

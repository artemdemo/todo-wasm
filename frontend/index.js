const toDoModel = {
    addToDo: null,
    getToDo: null,
    getAllToDo: null,
    deleteToDo: null,
    getLength: null,
};

const onInit = () => {
    toDoModel.addToDo = Module.cwrap(
        '_addToDo',
        'number',
        ['string', 'boolean']
    )
    toDoModel.getToDo = (todoId) => {
        const todoPointer = Module.asm.__getToDo(todoId);
        const todoString = Module.Pointer_stringify(todoPointer);
        let todo = null;
        try {
            todo = JSON.parse(todoString);
        } catch(e) {}
        return todo;
    };
    toDoModel.getAllToDo = () => {
        const allTodosPointer = Module.asm.__getAllToDo();
        const allTodosString = Module.Pointer_stringify(allTodosPointer);
        let todos = null;
        try {
            todos = JSON.parse(allTodosString);
        } catch(e) {}
        return todos;
    }
    toDoModel.deleteToDo = todoId => Module.asm.__deleteToDo(todoId);
    toDoModel.getLength = () => Module.asm.__getToDoListLength();
    
    toDoModel.addToDo('Some title', false);
    toDoModel.addToDo('Some title', false);
    toDoModel.addToDo('Some other title', true);
    toDoModel.addToDo('This should be deleted', true);
    toDoModel.addToDo('Another title', true);
    console.log(toDoModel.getToDo(0));
    console.log(toDoModel.getAllToDo());
    toDoModel.deleteToDo(2);
    console.log(toDoModel.getToDo(20));
    console.log(toDoModel.getAllToDo());
};

window.addEventListener('DOMContentLoaded', function() {
    /**
     * `Module.onRuntimeInitialized`
     * If set, this function is called when the runtime is fully initialized,
     * that is, when compiled code is safe to run.
     * @link https://kripken.github.io/emscripten-site/docs/api_reference/module.html#Module.onRuntimeInitialized
     */
    Module.onRuntimeInitialized = onInit;
});

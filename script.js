let orderQueue = [];
let orderHistory = [];
let currentOrder = null;

// Ingredient selection for each item type
const ingredientsMap = {
    'Burger': ['Cheese', 'Lettuce', 'Tomato', 'Pickles', 'Onion'],
    'Sandwich': ['Cheese', 'Lettuce', 'Tomato', 'Mayonnaise', 'Cucumber'],
    'Pizza': ['Cheese', 'Pepperoni', 'Olives', 'Mushrooms', 'Onions'],
    'Cold-drink': ['Small', 'Medium', 'Large'],
    'Hot-dog': ['Ketchup', 'Mustard', 'Onions', 'Relish', 'Cheese']
};

// Function to show checkboxes for ingredients
function showIngredients(itemName) {
    currentOrder = { name: itemName, ingredients: [] };
    
    const ingredients = ingredientsMap[itemName];
    const customizeSection = document.getElementById('customizeSection');
    
    let html = `<h3>${itemName}</h3><div class="checkbox-group">`;

    ingredients.forEach((ingredient, index) => {
        html += `
            <label>
                <input type="checkbox" id="ingredient${index}" value="${ingredient}">
                ${ingredient}
            </label>`;
    });

    html += `</div>`;
    
    customizeSection.innerHTML = html;

    document.getElementById('addOrderButton').style.display = 'inline';
}

// Add selected ingredients to the order and queue it
function addOrder() {
    const ingredients = ingredientsMap[currentOrder.name];
    currentOrder.ingredients = [];

    ingredients.forEach((ingredient, index) => {
        const checkbox = document.getElementById(`ingredient${index}`);
        if (checkbox && checkbox.checked) {
            currentOrder.ingredients.push(checkbox.value);
        }
    });

    // If no ingredients selected, add a default ingredient
    if (currentOrder.ingredients.length === 0) {
        currentOrder.ingredients.push(ingredients[0]); // Default to first ingredient
    }

    orderQueue.push(currentOrder);
    displayOrderQueue();

    // Reset the customization area
    document.getElementById('customizeSection').innerHTML = '<p>Select an item to customize!</p>';
    document.getElementById('addOrderButton').style.display = 'none';
    currentOrder = null;
}

// Display the order queue
function displayOrderQueue() {
    const orderQueueDiv = document.getElementById('orderQueue');
    if (orderQueue.length === 0) {
        orderQueueDiv.innerHTML = '<p>No orders in the queue.</p>';
    } else {
        let queueContent = '<ul>';
        orderQueue.forEach(order => {
            queueContent += `<li>${order.name} with ingredients: ${order.ingredients.join(', ')}</li>`;
        });
        queueContent += '</ul>';
        orderQueueDiv.innerHTML = queueContent;
    }
}

// Serve the next order in the queue
function serveNextOrder() {
    if (orderQueue.length > 0) {
        let servedOrder = orderQueue.shift();
        orderHistory.push(servedOrder);
        displayOrderQueue();
        displayOrderHistory();
    } else {
        alert("No orders in the queue to serve!");
    }
}

// Display the order history
function displayOrderHistory() {
    const orderHistoryDiv = document.getElementById('orderHistory');
    if (orderHistory.length === 0) {
        orderHistoryDiv.innerHTML = '<p>No orders have been served yet.</p>';
    } else {
        let historyContent = '<ul>';
        orderHistory.forEach(order => {
            historyContent += `<li>${order.name} with ingredients: ${order.ingredients.join(', ')}</li>`;
        });
        historyContent += '</ul>';
        orderHistoryDiv.innerHTML = historyContent;
    }
}

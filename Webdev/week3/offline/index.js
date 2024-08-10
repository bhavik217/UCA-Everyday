function renderProducts() {
    var productsListFromServer;

    function fetchProductList() {
        console.log("Fetching product list from server");
        // Assuming `productsList` is a global variable or fetched from a server.
        productsListFromServer = productsList; 
        initProductItem();
    }

    function initProductItem() {
        console.log("Initializing product items HTML Table");
        if (!productsListFromServer || productsListFromServer.length === 0) {
            document.getElementById("productMenu").innerHTML = getLoader();
            return;
        }

        document.getElementById("productMenu").innerHTML = `
        <h3>List of Products</h3>
        <table>
            <thead>
                <tr>
                    <th>Serial No.</th>
                    <th>Product Name</th>
                    <th>Description</th>
                    <th>Price</th>
                </tr>
            </thead>
            <tbody>
                ${getProductListUsingMap()}
            </tbody>
        </table>`;
    }

    function getLoader() {
        return `<h1>Loading Data</h1>`;
    }

    function getProductListUsingMap() {
        return productsListFromServer.map((item, index) => `
            <tr>
                <td>${index + 1}</td>
                <td>${item.name}</td>
                <td>${item.description}</td>
                <td>${item.price}</td>
            </tr>`).join("");
    }

    setTimeout(fetchProductList, 1000);
}

renderProducts();

import { useEffect, useState } from 'react';
import './App.css';
import axios from 'axios';

function App() {
  const [products, setProduct] = useState([]);

  useEffect(() => {
    axios.get('/api/products')
      .then((response) => setProduct(response.data))
      .catch((error) => console.log("Error fetching products:", error));
  }, []);  

  return (
    <>
      <h1>Hello</h1>
      <p>Products : {products.length}</p>

      {
        products.map((product) => (
          <div key={product.id}>
            <h3>Product - {product.name}</h3>
            <h3>Color - {product.color}</h3>
          </div>
        ))
      }
    </>
  );
}

export default App;
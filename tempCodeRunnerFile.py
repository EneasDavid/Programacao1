from selenium import webdriver
from selenium.webdriver.common.keys import Keys
import time

# Configurar o caminho para o webdriver do Microsoft Edge
edge_driver_path = 'Caminho/para/seu/msedgedriver.exe'  # Substitua pelo caminho correto

# Configurar o número de pesquisas desejado
num_pesquisas = 30

# Lista de termos de pesquisa
termos_pesquisa = [
    "Python tutorial",
    "Machine learning",
    "Web scraping",
    "Data visualization",
    # Adicione mais termos de pesquisa conforme necessário
]

# Iniciar o navegador Microsoft Edge
driver = webdriver.Edge(executable_path=edge_driver_path)

try:
    for i in range(num_pesquisas):
        # Escolher um termo de pesquisa aleatório da lista
        termo_pesquisa = random.choice(termos_pesquisa)

        # Abrir uma nova guia e navegar para o mecanismo de pesquisa (por exemplo, o Google)
        driver.execute_script("window.open('about:blank', '_blank');")
        driver.switch_to.window(driver.window_handles[-1])
        driver.get("https://www.google.com")

        # Localizar o campo de pesquisa e inserir o termo de pesquisa
        campo_pesquisa = driver.find_element_by_name("q")
        campo_pesquisa.send_keys(termo_pesquisa)
        campo_pesquisa.send_keys(Keys.RETURN)

        # Esperar um tempo antes de fechar a guia
        time.sleep(2)

        # Fechar a guia atual
        driver.close()

        # Mudar o foco de volta para a primeira guia
        driver.switch_to.window(driver.window_handles[0])

finally:
    # Fechar o navegador
    driver.quit()

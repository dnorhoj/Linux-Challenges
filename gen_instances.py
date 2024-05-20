import yaml
import sys

if len(sys.argv) < 2:
    print("Usage: gen_instances.py [amount]")
    exit(1)

try:
    instances = int(sys.argv[1])
except:
    print("Please enter a valid amount!")
    exit(1)

compose_dict = {
    "services": {}
}

for i in range(1, instances + 1):
    compose_dict["services"][f"chal_{i}"] = {
        "image": "chal",
        "ports": [f"{2200 + i}:22"],
        "hostname": f"codingpirates_{i}"
    }

with open('docker-compose.yml', 'w') as file:
    documents = yaml.dump(compose_dict, file)

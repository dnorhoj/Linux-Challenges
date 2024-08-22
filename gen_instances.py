import yaml
import click
from sys import stdout


@click.command()
@click.option("--dev", "-d", is_flag=True, help="Make it build image instead of using image")
@click.option("--image", "-i", default="linux-challenge", help="The name of the docker image")
@click.option("--hostname_prefix", "-h", default="challenge_", help="Prefix of docker container's hostname")
@click.option("--file", "-f", default="docker-compose.yml", help="File to output to")
@click.argument("amount", type=int, default=1)
def command(amount: int, dev: bool, image: str, hostname_prefix: str, file: str):
    compose_dict = {
        "services": {}
    }

    for i in range(1, amount + 1):
        service = {}

        if dev:
            service["build"] = {
                "context": "."
            }
        else:
            service["image"] = image

        service["ports"] = [f"{2200 + i}:22"]
        service["hostname"] = hostname_prefix + str(i)

        compose_dict["services"][f"instance_{i}"] = service

    if file == '-':
        yaml.dump(compose_dict, stdout)
        return

    with open('docker-compose.yml', 'w') as file:
        yaml.dump(compose_dict, file)


if __name__ == '__main__':
    command()
